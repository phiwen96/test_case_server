#pragma once
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ph_network/network.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::system;

auto main (int argc, char** argv) -> int;








