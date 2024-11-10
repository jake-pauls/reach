#pragma once

namespace pillar
{
    class App;

    class Win32Window
    {
    public:
        Win32Window() = default;

        /// @brief Initializes the Win32Window and shows it on screen.
        /// @param app Instance of the app being run, this is used to set a pointer to the application to be WndProc accessible in `CreateWindow`
        /// @param hInstance Handle for the currently running instance
        /// @param nCmdShow Display code for the window being spawned
        void Init(App* app, HINSTANCE hInstance, i32 nCmdShow);

        /// @brief Peeks the next message in the command queue.
        /// @param msg Reference to a message to peek, translate, and dispatch
        void Peek(LPMSG msg) const;

        /// @brief Destroys the active window.
        void Teardown();

    protected:
        /// @brief De facto window proc for the Win32Window
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        HWND m_Hwnd;
    };
}