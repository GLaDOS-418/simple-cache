#include "./controller/CacheController.h"
#include "./AppComponent.h"

#include "oatpp/network/Server.hpp"

#include <iostream>

void run() {

  /* Register Components in scope of run() method */
    AppComponent components{ "localhost", 8000 };

  /* Get router component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  /* Create MyController and add all of its endpoints to router */
  auto cacheController = std::make_shared<CacheController>();
  cacheController->addEndpointsToRouter(router);

  /* Get connection handler component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

  /* Get connection provider component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
  oatpp::network::Server server(connectionProvider, connectionHandler);

  /* Priny info about server port */
  OATPP_LOGI("Cache", "Server running on port %s", connectionProvider->getProperty("port").getData());

  /* Run server */
  server.run();
  
}

int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();

  run();
  
  oatpp::base::Environment::destroy();
  
  return 0;
}
