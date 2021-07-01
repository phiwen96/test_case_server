#include "main.hpp"



static_assert (String <std::string>, "");
//static_assert (String <std::string const&>, "");

auto test (String auto&& s)
{
    
}


#define PORT 3333

/**
 The size of the queue containing the pending connection
 requests.
 */
#define QUEUE_SIZE_FOR_PENDING_CONNECTIONS 30



auto run_server = [] (Number auto port, Number auto pending_connections)
{
    auto ios = io_service {};
    auto error = error_code {};
    
    /**
     create an endpoint representing all IP addresses
     available on the host and the specified port number
     */
    auto server_endpoint = tcp::endpoint {address_v6::any (), static_cast <unsigned short> (port)};
    
    /**
     A passive socket that is used to wait for connection
     establishment requests from remote applications
     that communicate over the TCP protocol.
     */
    auto acceptor_socket = tcp::acceptor {ios, server_endpoint.protocol ()};
    

    
    /**
     binding the acceptor socket to the server endpoint to get
     ready for listening for incoming connection requests.
     */
    acceptor_socket.bind (server_endpoint, error);
    
    /**
     Starting to listen for incoming connection
     requests.
     */
    acceptor_socket.listen (pending_connections);
    
    /**
     Creating an active socket.
     */
    
    auto client_socket = tcp::socket {ios};
    
    acceptor_socket.accept (client_socket);
};







auto main (int, char**) -> int
{
    auto buf = streambuf {};
    auto output = std::ostream {&buf};
    
    
    
    output << "hej" << "då";
    
    auto input = std::istream {&buf};
    
    auto string = std::string {};
    
    std::getline (input, string);
    std::cout << string << std::endl;
    
//    run_server (3333, QUEUE_SIZE_FOR_PENDING_CONNECTIONS);
    
    return 0;
}




