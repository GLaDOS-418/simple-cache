# Simple Key-Value Store

![application flow](./docs/flow.png "flow chart")

### Features

- multithreaded (using Oat++ simple API).
- thread safe ( uses reader-writer pattern )
- supports multiple clients
- REST server
- vlidates key (keys with spaces are invalid)

### TODO

- make it exception safe
- add swagger support
- add docker support
- handle server errors better
- improve cache implementation by implementing e.g. utf support, probabilistic DS like bloom filters, scaling options

### Project layout

```
.
├── CMakeLists.txt          // projects CMakeLists.txt
├── conanfile.txt           // third party dependencies
├── src
│   ├── cache               // LRU Cache Implementation
│   ├── controller          // CacheController
│   ├── dto                 // DTOs for req and res
│   └── server              // main() and server config
└── test                    // test folder
```

---

### Build and Run

- install [conan](https://www.conan.io) from pip.
- install [Oat++(AKA oatpp)](https://oatpp.io/) third party dependency using conan package manager.

```
$ mkdir build && cd build
$ conan install .. --remote=conancenter --build=missing
$ cmake ..
$ cmake . --build
$ ./kv_store-exe  # - run application.
```

- install [postman](https://www.postman.com/) and import `postman.api_tests.json` and run tests.

### NOTE

It's based on the [oatpp-starter project](https://github.com/oatpp/oatpp-starter).

