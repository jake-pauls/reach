#pragma once

namespace pillar
{
    class App;

    class Win32Window
    {
    public:
        Win32Window() = default;

        void Init(App* app, HINSTANCE hInstance, int nCmdShow);
        void Peek(LPMSG msg) const;
        void Teardown();

        const HWND& GetHWND() const { return m_Hwnd; }

    protected:
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        HWND m_Hwnd;
    };
}