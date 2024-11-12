# BlackStudy-RPC

## Interface Definition Language (.idl)
    IDL (Interface Definition Language) files in C++ projects are used to define interfaces
    for communication between different components, often in distributed systems or
    applications using RPCs (Remote Procedure Calls). 
    These files describe methods, interfaces, and data structures independently of any specific programming language. 
    An IDL compiler then processes the file to generate language-specific code (e.g., `.h` and `.cpp` files for C++), enabling interoperability between components, even if they are
    written in different languages or located on separate systems.

    Link: https://www.omg.org/spec/IDL/4.2/About-IDL/

## Stubs
    In the context of Remote Procedure Calls (RPC), stubs are intermediary pieces of code generated to enable communication between a client and a server. 
    They simplify the process of calling remote functions by handling the complexity of network communication and data serialization.

        Client Stub: Acts as a proxy for the remote function on the client side. 
        It packages the function arguments into a message, sends it over the network to the server, and then unpacks the response when it is received.

        Server Stub: On the server side, the stub receives the request, unpacks the arguments, calls the actual function, and then sends the result back to the client stub.

    Stubs are generated automatically from an Interface Definition Language (IDL) file using a tool like MIDL. 
    The client and server use these stubs to seamlessly call remote functions as if they were local, abstracting the network details from the programmer.
