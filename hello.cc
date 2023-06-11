#include <napi.h>
#include <windows.h>

typedef void (*Hello_from_rust)(void); // 定义函数指针类型
Hello_from_rust func1;
HMODULE module;



Napi::String Method(const Napi::CallbackInfo &info)
{
    func1();
    Napi::Env env = info.Env();
    return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    // 运行时加载DLL库
    module = LoadLibraryA(R"(./screensnap.dll)"); // 根据DLL文件名，加载DLL，返回一个模块句柄
    if (module == NULL)
    {
        printf("加载rust2.dll动态库失败\n");
    }
    printf("加载rust2.dll动态库success\n");

    // 导出函数地址
    func1 = (Hello_from_rust)GetProcAddress(module, "hello_from_rust"); // GetProcAddress返回指向的函数名的函数地址
    exports.Set(Napi::String::New(env, "hello"),
                Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(hello, Init)