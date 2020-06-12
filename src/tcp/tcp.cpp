#include "tcp.h"
#include<iostream>
#include<boost/asio.hpp>
#include<string>
#include<vector>
#include<utility>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

#define mp std::make_pair;

TCP::TCP(){
    // Define IO_CONTEXT
    try{

    IO = std::make_shared<IOCONTEXT>();

    // Define IP_ADDRESS
    std::string IP_address = "10.0.0.177";
    unsigned short port_num = 5000;
    IP = std::make_shared<IPADDRESS>(IPADDRESS::from_string(IP_address));

    // Define Endpoint
    EP = std::make_shared<ENDPOINT>(*IP,port_num);

    // Define Socket
    SOCK = std::make_shared<SOCKET>(*IO,EP->protocol());
    



    } catch(boost::system::system_error &e){
        // Any error until opening sockets
        cout<<e.what()<<endl;
    }

}
