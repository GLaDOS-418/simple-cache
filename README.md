# Simple Key-Value Store

Based of the starter project of [Oat++(AKA oatpp)](https://oatpp.io/) application using the multithreaded(simple) API.

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

- install oat++ third party dependency using [conan](https://www.conan.io) package manager.

```
$ mkdir build && cd build
$ conan install .. --remote=conancenter --build=missing
$ cmake ..
$ make
$ ./kv_store-exe  # - run application.

```
