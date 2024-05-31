#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"

int main(int argc,char **argv)
{
    // 整个程序启动以后，想使用mprpc框架享受rpc调用，需要调用框架初始化操作（只初始化一次）
    MprpcApplication::Init(argc,argv);
    
    //演示调用远程调用rpc方法的login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    fixbug::LoginRequest request; // rpc的请求参数
    request.set_name("zhang san");
    request.set_pwd("123456");
    fixbug::LoginResponse response;// rpc的响应参数

    //发起rpc的调用
    stub.Login(nullptr,&request,&response,nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读取调用结果
    if (0 == response.result().errcode())
    {
        std::cout << " rpc login response success: "<< response.success() <<std::endl;
    }
    else
    {
        std::cout << "rpc login response error :" << response.result().errmsg() << std::endl;
    }

    // 演示调用rpc方法Register
    fixbug::RegisterRequest req;
    req.set_id(20000);
    req.set_name("mprpc");
    req.set_pwd("666666");
    fixbug::RegisterResponse rsp;

    //以同步的方式发起rpc调用请求，等待返回结果
    stub.Register(nullptr,&req,&rsp,nullptr);

     // 一次rpc调用完成，读取调用结果
    if (0 == rsp.result().errcode())
    {
        std::cout << " rpc register response success: "<< rsp.success() <<std::endl;
    }
    else
    {
        std::cout << "rpc register response error :" << rsp.result().errmsg() << std::endl;
    }



    return 0;
}