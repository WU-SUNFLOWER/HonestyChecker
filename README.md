# HonestyChecker

HonestyChecker is a code plagiarism detection tool written in modern C++.

In general, this project reproduces the [SIM](https://www.dickgrune.com/Programs/similarity_tester/index.html) code plagiarism detection algorithm proposed by [Professor Dick Grune](https://www.dickgrune.com/) from Vrije Universiteit.

What's more, this project has the following extra features:
- Developed using C++ object-oriented programming style, making it easy to extend or modify the project in the future.
- Added support for plagiarism detection in Python code.
- Supports development and building on both Windows platforms (Visual Studio 2022) and Linux platforms (make & g++).
- Supports outputting dynamic link libraries that can be called by the CPython interpreter on both platforms. Python developers can easily invoke the high-performance algorithm interfaces provided by HonestyChecker in their own applications. You can see the [example](https://github.com/WU-SUNFLOWER/HonestyChecker/blob/2024.07.10/tools/test_python_interface.py) here.

# Build

## Windows

I select Microsoft Visual Studio as the build tool in Windows platform.

If you just want to build a .exe file to test HonestyChecker, it's very easy for anyone who has learned C/C++ development in Windows platform. 

I just want to remind you not forget to modify `int main()` function to meet your own needs

If you want to build a .pyd file to let your Python program to call the API provided by HonestyChecker, things won't be that easy to handle anymore.

You have to install CPython on your computer, and maybe you have to modify some options in Visual Studio. 

Here are some documents for your reference:
- https://learn.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2022
- https://blog.csdn.net/ZChen1996/article/details/116004672

## Linux

I have offered the `Makefile` script in this project. Since most Linux systems (like Ubuntu) has built-in *make*, *g++* and *CPython*, things are easy to handle.

Here are some building command tips:

- `make normal`: You will get an executable file `HonestyChecker` in the `dist` directory. Just like in Windows, don't forget to modify the `int main()` function by yourself!
- `make python`: You will get an shared library `libHonestyChecker.so` in the `dist` directory.
- `make clean`: Remove all the temporary files (`obj` directory) and compiler results (`dist` directory).
