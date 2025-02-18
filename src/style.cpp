#include "style.hpp"

#include <imgui.h>

#include "colors.hpp"

ImVec4 accent_color = Colors::BLUE;

void SetAccentColor(ImVec4 color) {
    accent_color = color;
    Style();
}

void Style() {
    ImGuiStyle &style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 8.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_None;
    style.ChildRounding = 8.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 8.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 8.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 5.0f);
    style.ItemInnerSpacing = ImVec2(5.0f, 5.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 20.0f;
    style.ColumnsMinSpacing = 5.0f;
    style.ScrollbarSize = 16.0f;
    style.ScrollbarRounding = 8.0f;
    style.GrabMinSize = 8.0f;
    style.GrabRounding = 8.0f;
    style.TabRounding = 8.0f;
    style.TabBorderSize = 0.0f;
    style.TabCloseButtonMinWidthSelected = 0.0f;
    style.TabCloseButtonMinWidthUnselected = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.16f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.23f, 0.23f, 0.3f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.17f, 0.17f, 0.23f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.28f, 0.28f, 0.37f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.28f, 0.28f, 0.37f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.1f, 0.13f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1f, 0.1f, 0.13f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1f, 0.1f, 0.13f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1f, 0.1f, 0.13f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1f, 0.1f, 0.13f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = accent_color;
    style.Colors[ImGuiCol_ScrollbarGrabActive] = accent_color;
    style.Colors[ImGuiCol_CheckMark] = accent_color;
    style.Colors[ImGuiCol_SliderGrab] = accent_color;
    style.Colors[ImGuiCol_SliderGrabActive] = accent_color;
    style.Colors[ImGuiCol_Button] = ImVec4(0.17f, 0.17f, 0.23f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.28f, 0.37f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = accent_color;
    style.Colors[ImGuiCol_Header] = ImVec4(0.17f, 0.17f, 0.23f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.28f, 0.28f, 0.37f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.28f, 0.28f, 0.37f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = accent_color;
    style.Colors[ImGuiCol_SeparatorActive] = accent_color;
    style.Colors[ImGuiCol_ResizeGrip] = accent_color;
    style.Colors[ImGuiCol_ResizeGripHovered] = accent_color;
    style.Colors[ImGuiCol_ResizeGripActive] = accent_color;
    style.Colors[ImGuiCol_Tab] = ImVec4(0.23f, 0.23f, 0.3f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] =
        ImVec4(accent_color.x, accent_color.y, accent_color.z, 0.6f);
    ;
    style.Colors[ImGuiCol_TabActive] = ImVec4(accent_color.x, accent_color.y, accent_color.z, 0.6f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.23f, 0.23f, 0.3f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = accent_color;
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.94f, 0.55f, 0.35f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.94f, 0.78f, 0.47f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.94f, 0.55f, 0.35f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.28f, 0.28f, 0.37f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.7f, 0.7f, 0.7f, 0.5f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.7f, 0.7f, 0.7f, 0.5f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.17f, 0.17f, 0.23f, 1.0f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 1.0f, 0.35f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.9f);
    style.Colors[ImGuiCol_NavHighlight] = accent_color;
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.5f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.31f);
}

void SetScale(f32 scale) {
    ImGuiStyle &style = ImGui::GetStyle();
    style.ScaleAllSizes(scale);
}
