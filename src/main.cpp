#include "main.hpp"




#define PORT 3333

/**
 The size of the queue containing the pending connection
 requests.
 */
#define PENDING_CONNECTIONS_QUEUE_SIZE 30

auto main (int argc, char** argv) -> int
{
    

    
    auto ios = io_service {};
    auto error = error_code {};
    
    /**
     create an endpoint representing all IP addresses
     available on the host and the specified port number
     */
    auto server_endpoint = tcp::endpoint {address_v6::any (), PORT};
    
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
    acceptor_socket.listen (PENDING_CONNECTIONS_QUEUE_SIZE);
    
    /**
     Creating an active socket.
     */
    
    auto client_socket = tcp::socket {ios};
    
    acceptor_socket.accept (client_socket);
    
    
    
    
}




