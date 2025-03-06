#pragma once

#include <sys/uio.h>
#include <unistd.h>

#include <optional>
#include <string>
#include <vector>

#include "config.hpp"
#include "globals.hpp"
#include "types.hpp"

class Process {
  public:
    i32 pid = 0;
    i32 mem = -1;

    template <typename T>
    T Read(const u64 address) {
        if (!flags.file_mem) {
            T value;
            const iovec local_iov = {.iov_base = &value, .iov_len = sizeof(T)};
            const iovec remote_iov = {
                .iov_base = reinterpret_cast<void *>(address), .iov_len = sizeof(T)};
            process_vm_readv(pid, &local_iov, 1, &remote_iov, 1, 0);
            return value;
        }
        T value;
        pread(mem, &value, sizeof(value), address);
        return value;
    }

    template <typename T>
    void Write(const u64 address, T value) {
        if (!flags.file_mem) {
            const iovec local_iov = {.iov_base = &value, .iov_len = sizeof(T)};
            const iovec remote_iov = {
                .iov_base = reinterpret_cast<void *>(address), .iov_len = sizeof(T)};
            process_vm_writev(pid, &local_iov, 1, &remote_iov, 1, 0);
        } else {
            pwrite(mem, &value, sizeof(value), address);
        }
    }

    std::string ReadString(u64 address);
    void ReadString(u64 address, std::string &value);
    std::vector<u8> ReadBytes(u64 address, u64 count) const;

    std::optional<u64> GetModuleBaseAddress(const std::string &module_name) const;
    u64 ModuleSize(u64 module_address);
    std::vector<u8> DumpModule(u64 module_address);
    std::optional<u64> ScanPattern(
        const std::vector<u8> &pattern, const std::vector<bool> &mask, u64 length,
        u64 module_address);
    u64 GetRelativeAddress(u64 instruction, u64 offset, u64 instruction_size);
    std::optional<u64> GetInterfaceOffset(u64 module_address, const std::string &interface_name);
    std::optional<u64> GetModuleExport(u64 module_address, const std::string &export_name);
    std::optional<u64> GetAddressFromDynamicSection(u64 module_address, u64 tag);
    std::optional<u64> GetSegmentFromPht(u64 module_address, u64 tag);
    std::optional<u64> GetConvar(u64 convar_offset, const std::string &convar_name);
    u64 GetInterfaceFunction(u64 interface_address, u64 index);
};

std::optional<i32> GetPid(const std::string &process_name);
bool ValidatePid(i32 pid);
std::optional<Process> OpenProcess(i32 pid);
