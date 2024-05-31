# aux_source_directory(. SRC_LIST)
set(SRC_LIST 
    mprpcapplication.cc 
    mprpcconfig.cc 
    rpcheader.pb.cc 
    rpcprovider.cc 
    mprpcchannel.cc
    mprpccontroller.cc
    logger.cc
    zookeeperutil.cc)
add_library(mprpc ${SRC_LIST})

# 设置 zookeeper 静态库路径
set(ZOOKEEPER_MT_LIB /usr/local/lib/libzookeeper_mt.a)

target_link_libraries(mprpc muduo_net muduo_base pthread ${ZOOKEEPER_MT_LIB})