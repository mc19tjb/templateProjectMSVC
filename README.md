# Template MSVC C++ Project

![GitHub language count](https://img.shields.io/github/languages/count/mc19tjb/:repo?style=flat-square&logoSize=auto)
![GitHub top language](https://img.shields.io/github/languages/top/mc19tjb/:repo?style=flat-square&logoSize=auto)
![GitHub License](https://img.shields.io/github/license/mc19tjb/:repo?style=flat-square&logoSize=auto)
![GitHub repo file or directory count](https://img.shields.io/github/directory-file-count/mc19tjb/:repo?style=flat-square&logoSize=auto)
![Static Badge](https://img.shields.io/badge/Pull_Requests-Off-red?style=flat-square&logoSize=auto)

## About
This is a template project demonstrating software development on VS Code, using the MSVC cl compiler and Visual Studio C++ Desktop Compilation SDK alongside a complete C++ toolchain including:
* package management (vcpkg) 
* meta-build systems (CMake)
* testing frameworks (GTest downloaded via vcpkg)
* Version Control (Git)
* Documentation Generation (Doxygen)

It includes a small calculator executable and an associated test suite made using the GTest API, to ensure the toolchain is set up correctly and see how a C++ development environment can be integrated into VS Code.
The code can be compiled both on the command line and via VS Code's UI (using the CMake Tools Extension) and can be used as a template for C++ projects in VS Code, or adapted for developing software in an offline environment.

Whilst intended for developing software on/for windows machines, this project could be used as a template for  development on other architectures, or using other toolchain elements (e.g. using Conan instead of vcpkg, or writing code for Linux instead of Windows), however this would require editing the CMakePresets and CMakeLists.txt files to ensure it works as intended - when on windows these should be ready to go with minimal setup.

Essentially, this project can be used to set up the whole developer toolchain when starting a new C++ project in VS Code.



### Intended Audience & Readme Format
The developers of this project assume anyone using it has a background knowledge of all elements in the toolchain (see the dependencies section), however, not much knowledge of how to integrate them into an IDE/VS Code. As such, any introduction into how to use toolchain elements will be brief, as we assume you know what these do, but there will be explanations of how to avoid common pitfalls when using these in an IDE/VS Code in this readme, and some of the included files, even where this may make some files seem verbose or where explanations woud usually be left out.

As a template project showcasing a C++ development toolchain in VS Code, many sections of this readme will be split into two parts, one detailing relevant information for the toolchain, and another showing information for the included software for each section.  

Similarly, there are many ways to set up and use toolchains in VS Code - far too many to explicitly state and provide guides for in this readme.

In light of this, where possible the readme will show 3 ways to use the set up toolchain within VS Code:

1. Using the CMake Tools UI
2. Using CMake Tools command pallete instructions accessed using `ctrl + shift + p`
3. Using the command line in the VS Code terminal accessed using `ctrl + '`
> [!note]    
> Remember: MSVC in VS Code is a Multi-config generator, meaning some terminal commands may need to specify the configuration to work. For more information on using CMake with multi-config generators, see [CMake's Tutorial Section on Single vs Multi-config Generators](https://cmake.org/cmake/help/latest/guide/tutorial/Before%20You%20Begin.html#single-and-multi-configuration-generators)

However, for more in depth tutorials on how to use these methods, refer to each's supporting documentation.

## Installation Guide 
### Dependencies
#### Toolchain
As a template project, this project has few dependencies needed to build and run the code, however we strongly recommend installing the following toolchain components on your machine, as this project is configured to use them. Where possible, it is recommended to install via a GUI installer to make adding them to environment variables easier:
* **C++ [VERSION]**
* **CMake (Version 4.0)**
  * Meta-Build system used to generate build files and control project compilation and building. 
  * We recommend downloading the latest version of CMake, as newer versions are backwards comptible with projects using older versions. However, if this is not possible, we recommend using at least version 3.23, as the FILE_SET arguement (used to group library/source headers together), and support for CMake Presets version 4 (used by this project's CMakePresets file) was added in this version.
  * While we can't ensure every part of CMakeLists.txt will work with Cmake version 3.23, using an older version of Cmake will instantly fail to compile.
  > [!note]
  > When Installing, remember to click the `Add Cmake to PATH` box under `Installation Options` to ensure CMake can be accessed from any program or terminal. 
* **Cmake Compatible C++ Compiler (MSVC Recommended)**
  * Needed to turn your project's source code into an executable.
  * A list of Cmake compatible compilers can be found [here](https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#supported-compilers), however, if compiling on windows, or using either VS Code or Visual Studio we *strongly recommend* using the compiler supplied with **MSVC C++ Desktop Development tools**, as this will integrate into the CMake Tools extension, and has the most support from package managers.
    * Instructions on downloading MSVC C++ Desktop Development tools and the compiler supplied with them can be found on the [Configure VS Code for Microsoft C++](https://code.visualstudio.com/docs/cpp/config-msvc) webpage.
* **Vcpkg Package Manager**
  * Handles downloading third party libraries and gives instructions on how to link them into a CMake project.
  * Vcpkg can be downloaded as part of the MSVC installation (C++ for desktop development sdk)
    * The tutorial for how to set up vcpkg from this installation can be found on the Microsoft Devblog announcing [vcpkg is Now Included with Visual Studio](https://devblogs.microsoft.com/cppblog/vcpkg-is-now-included-with-visual-studio/).
    > [!caution]
    > The version of vcpkg downloaded as part of the MSVC C++ Desktop or Gaming Workloads *doesn't* support vcpkg classic mode, *only* vcpkg manifest mode.
  * Vcpkg can also be downloaded as a standalone program.
    * The tutorial for how to set up vcpkg from this installation can be found in the [vcpkg with CMake in VS Code Tutorial](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode?pivots=shell-powershell)
  > [!note]
  > Vcpkg doesn't need to be added to your system environment variables: in this project it's path is set as a local environment variable during [toolchain setup](#toolchain-setup).
* **Git**
  * Used for this project's version control.
  * Git for windows can be installed [here.](https://git-scm.com/install/windows "Download git for windows here.")
  > [!note]
  > When Installing, remember to click the  recommended `Git from the Command Line and also from Third Party Software` box under `Adjusting your PATH environment` to ensure git can be accessed from any program or terminal.
* **Doxygen**
  * Needed to generate project documentation. 
  * Other documentation tools are available, however doxygen can be directly integrated into CMake and controlled within the project's CMakeLists.txt using it's [FindDoxygen Module](https://cmake.org/cmake/help/latest/module/FindDoxygen.html  "Documentation on the Module integrating doxygen into CMake") and associated commands. 
  * If `ENABLE_DOXYGEN_INTEGRATION` is set to `ON`, the project will fail to compile if doxygen can't be found as the variable sets it as a required package for the project.
    * You can download it [here](https://www.doxygen.nl/download.html "The downloads page of the official Doxygen website")
    > [!note]
    > The Doxygen Installer doesn't add the program to your PATH environment variable by default. To access it within VS Code, add it to your Environment variables as shown in the [toolchain setup section](#toolchain-setup).
* **CMake Tools VS Code Extension (version 1.7 or later)**
  * Provides a UI for configuring & building code, and running tests in VS Code using CMake.
  * Version 1.7 adds support for CMake Presets.
  * A guide on using CMake Tools in VS Code can be found in the [CMake Tools Docs](https://github.com/microsoft/vscode-cmake-tools/blob/HEAD/docs/README.md)

#### Executable
  All dependencies required by the executable are declared in the vcpkg manifest file (vcpkg.json) and should be downloaded automatically when the project is configured. However, for accurate record keeping they are also listed here.
  * **Gtest** 
    * Needed to run programs in test suite.
  * **FMT (?)**

### Setup
#### Toolchain Setup
1. Ensure you have all the toolchain dependencies installed on your machine.
2. Open your gitbash terminal in VS Code.
3. Navigate from the current directory to the location you want this project to be cloned to.
4. Clone this template onto your local machine using the git clone command on your terminal.
```
git clone [URL to your repository on github]
```
5. Ensure the CMake Tools Extension's `Use Cmake Presets` setting is set to `auto` or `always`.
  * Open the CMake Tools Extension settings by either:
    1. **CMake Tools UI**
      * Click the 'Open CMake Tools Extension Settings' icon in the CMake Tool's Project Status UI
    2. **Command Pallete**
      * Select CMake: Open CMake Tools Extension Settings command
    > [!note]    
    > Open the Command Pallete with `ctrl + shift + p` 
6. Set the VCPKG_ROOT environment variable as the path to your vcpkg installation (the path to the folder containing vcpkg.exe on your machine.)
  * This can be set in either CMakePresets, or the terminal command line, although it is strongly recommended to set it in CMakePresets using method B (creating a CMakeUserPresets.json) as this is the most explicit way of setting the variable, gives a clear indication of where the variable is set (letting you change this from one easy to access place), and can be saved on a local machine across sessions (setting VCPKG_ROOT via a terminal may require you to re-set VCPKG_ROOT every session) :

  **Setting VCPKG_ROOT in CMakePresets:**
  1. Replace all mentions of `$env{VCPKG_ROOT}` in CMakePresets.json with the path to your vcpkg installation.
  2. Create a CMakeUserPresets.json file in the project root directory, add presets that inherit the config preset from CMakePresets, and set `VCPKG_ROOT` as an environment variable, e.g.
  ```{.json}
          {
          "name": "user-preset-name",
          "displayName": "user-preset-name",
          "description": "Inherits compiler info from msvc in CMakePresets and sets environment variables",
          "inherits": "config-preset-from-CMakePresets.json-e.g-msvc",
          "environment": {
            "VCPKG_ROOT": "C:\\path\\to\\vcpkg"
           }
          }
  ```

  **Setting VCPKG_ROOT as an environment variable in the terminal:**
  3. Open a Developer Command Prompt for VS, set VCPKG_ROOT as the path to your vcpkg installation in the command prompt, then open VS Code from here, using terminal commands:
  ```
      set VCPKG_ROOT=path\to\vcpkg
  ``` 
  then
  ```
      code .
  ```
  * To see currently set variables in a Developer Command Prompt for VS, the following command will print them to the terminal:
  ```
      set
  ```
> [!warning] 
> BE ADVISED: Using this method ***will*** propogate the environment variables to VS Code, and let you use the CMake Tools UI with Presets that don't set VCPKG_ROOT. However, the user set variables ***are not*** saved between terminal sessions: as soon as you close the developer command prompt, VCPKG_ROOT is deleted, and you'll have to re-set it to your desired path when you open another terminal. ***Also***, VS Code windows not opened from the developer terminal **won't** have these variables set, and so won't work. 
      
  4. Open a Powershell terminal in VS Code using `ctrl + '` and set VCPKG_ROOT here using the commands:
  ```
          $env:VCPKG_ROOT = "C:\\Path\\to\\vcpkg"
  ```
      then
  ```
          $env:PATH = "$env:VCPKG_ROOT;$env:PATH" 
  ```

> [!warning] 
> BE ADVISED: using this method *only* sets this environment variable in the current powershell terminal. If you use this method, you *won't* be able to use the *CMake Tools* extension for configuring, building or testing - you'll only be able to use CMake from the currently open powershell terminal.

The Project should now be set up for configuring and building using the toolchain.

#### Executable Setup
  1. Set up Toolchain
  2. Configure project using one of the 3 methods below:
    1. **CMake Tools UI**
      * Click on the Configure preset's 'configure' icon in the CMake Tools Project Status UI
  > [!note]
  > If prompted to select a configure preset, ensure that VCPKG_ROOT is already set as an environment variable before configuring, or select a preset that sets VCPKG_ROOT or inherits a preset that does.
    2. **Command Pallete**
      * Select CMake: Configure command
  > [!note]    
  > Open the Command Pallete with `ctrl + shift + p`
  > [!note]
  > If prompted to select a configure preset, ensure that VCPKG_ROOT is already set as an environment variable before configuring, or select a preset that sets VCPKG_ROOT or inherits a preset that does.
    3. **VS Code Terminal**
      * Type the following when in the root-level directory:
      ```
        cmake --preset [presetName]
      ```
  > [!note]
  > If you set VCPKG_ROOT using CMakePresets (method A or B in toolchain setup setp 5.), make sure [presetName] is a preset that either sets this environment variable, or one that inherits a preset that does.  
    * If you want to download GTest and build the test suite to run tests, set option `BUILD_TESTS` to `ON` in root directory CMakeLists.txt before configuring.
    * If you want to build the doxygen documentation set up in `docs/CMakeLists.txt`, set option `ENABLE_DOXYGEN_INTEGRATION` to `ON` in root directory CMakeLists.txt before configuring.
  3. Build project in cmake using one of the 3 methods below:    
    1. **CMake Tools UI**
      * Click on the Build preset's 'build' icon in the CMake Tools Project Status UI
    2. **Command Pallete**
      * Select CMake: Build command
  > [!note]    
  > Open the Command Pallete with `ctrl + shift + p`
    3. **VS Code Terminal**
      * Type the following when in the root-level directory:
      ```
      cmake --build --preset [presetName]
      ```     
> [!note]    
> Make sure the preset is from CMakePresets or CMakeUserPresets and is associated with a configurePreset which sets VCPKG_ROOT explicitly, inherits a preset that does, or where this environment variable has been set using another method during toolchain setup.

## Usage
  ### Tests
  The project comes with two test suites built in: one to perform basic unit tests on the calculator, and one hello world style test program which tests no software but can be run to see if the tests have been discovered properly & how the tests are shown within VS Code.
  #### Building Tests
  To download GTest and build the test suite to run tests, set option `BUILD_TESTS` to `ON` using either of the following ways:
  1. **CMakeLists.txt** 
    * set the `BUILD_TESTS` option in the root [CMakeLists.txt](/CMakeLists.txt) to `ON`
  2. **CMake Presets**
    * Add `BUILD_TESTS` to a preset's cacheVariables object and set it's value to `ON` e.g.
  ```{.json}  
  {
    "name": "preset",
    "cacheVariables": {
                "BUILD_TESTS": "ON"
            }
  }          
  ```
  > [!note]    
  > Preset cache variables usually override option values set in CMakeLists.txt. For more information about setting variables to control CMake, see the [CMake Tutorial on Cache Variables](https://cmake.org/cmake/help/latest/guide/tutorial/Configuration%20and%20Cache%20Variables.html).
  3. **VS Code Terminal** 
    * Set `BUILD_TESTS` to `ON` when [configuring the project using the terminal](#executable-setup) by adding the following arguement to your cmake configure call:
  ```
      -DBUILD_TESTS=ON
  ```
  #### Running Tests 
  Once the executable and tests are built, you should be able to run the test suite using one of the 3 ways below:
  1. **CMake Tools UI**
    * Click on the Test preset's 'Run Tests' icon in CMake Tool's Project Status UI
  2. **Command Pallete**
    * Select CMake: Run Tests command
> [!note]    
> Open the Command Pallete with `ctrl + shift + p`
  3. **VS Code Terminal**
    * Navigate to the build directory (out/build/presetName) and run the following command
  ```
      ctest -C Debug
  ``` 
> [!note]    
> Remember: MSVC in VS Code is a Multi-config generator, so the command needs to specify what configuration to run tests on. For more information on using CTest with multi-config generators, see the build and run section of [CMake's CTest Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/Testing%20and%20CTest.html#build-and-run)
  ### Generating Documentation
  Documentation can be generated by setting the `ENABLE_DOXYGEN_INTEGRATION` option to `ON` (before configuring) in either of the following ways:
  1. **CMakeLists.txt** 
    * set the `ENABLE_DOXYGEN_INTEGRATION` option in the root [CMakeLists.txt](/CMakeLists.txt) to `ON`
  2. **CMake Presets**
    * Add `ENABLE_DOXYGEN_INTEGRATION` to a preset's cacheVariables object and set it's value to `ON` e.g.
  ```{.json}  
  {
    "name": "preset",
    "cacheVariables": {
                "ENABLE_DOXYGEN_INTEGRATION": "ON"
            }
  }          
  ```
  > [!note]    
  > Preset cache variables usually override option values set in CMakeLists.txt. For more information about setting variables to control CMake, see the [CMake Tutorial on Cache Variables](https://cmake.org/cmake/help/latest/guide/tutorial/Configuration%20and%20Cache%20Variables.html).
  3. **VS Code Terminal** 
    * Set `ENABLE_DOXYGEN_INTEGRATION` to `ON` when [configuring the project using the terminal](#executable-setup) by adding the following arguement to your cmake configure call:
  ```
      -DENABLE_DOXYGEN_INTEGRATION=ON
  ```
  > [!note]    
  > Remember to delete the CMakeCache when reconfiguring for this change to take effect, unless setting the option on the command line, otherwise it won't take effect and documentation won't be generated on your next build. This can be done manually, or using the command pallette command `CMake: Delete Cache and Reconfigure`.

The resulting documentation can be accessed by:
  1. Navigating to the correct output folder e.g. `out\build\presetName\` 
  2. Right clicking on `docs/html/index.html`
  3. Selecting `open in integrated browser`.


  ### Running Executable
  After building, run the executable using one of the 3 ways below:
  1. **CMake Tools UI**
    * Click on the Launch target's 'Run in Terminal' icon in CMake Tool's Project Status UI
  2. **VS Code UI**
    * Click the 'Launch the Selected Target in the terminal window' play button in the VS Code status bar along the bottom of the screen.
  3. **VS Code Terminal**
    * Navigate to the executable's location in the build/output directory and type the following in the terminal
  ```
  ./main.exe
  ``` 

  ### Installing Executable and Build Artifacts
  This project's CMakeLists.txts contain a rudimentary install script copying built targets and documentation to an install directory in `out/install/presetName`. This is meant as a cleanup & quality of life feature: allowing users to easily see what the project builds and access documentation without having to menu dive through a cluttered build directory, and **not** a way to package the project for use in separate projects or install the program on a user's machine.

  The built executable & documentation can be installed the following way:
  1. **Command Pallete**
    * Select CMake: Install command
> [!note]    
> Open the Command Pallete with `ctrl + shift + p`

  Installation limitations can be found under the [Installation Limitations](#installation-limitations) and [Documentation Limitations](#documentation-limitations) subheadings in this readme.

## Offline Usage
  ### Toolchain Offline
  The toolchain can be used to develop software without a reliable internet connection by downloading & exporting all required packages into a standalone sdk using the [vcpkg Exporting Packages Tutorial](https://learn.microsoft.com/en-us/vcpkg/produce/export-compiled-dependencies "Microsoft Learn's Tutorial on exporting packages in vcpkg"), and setting VCPKG_ROOT to the unzipped sdk path (full path to the exported folder) instead of your main system installation of vcpkg - using any of the methods in step 4 of the installation guide.

  > [!note] 
  > You will need an internet connection to first download the packages into the sdk, but not afterwards when consuming them later in your project's development.  
  ### Executable Offline
  Once the toolchain is setup for offline coding, software development can be done as normal.

## Limitations
  ### Toolchain Limitations
  #### Package Management Limitations
    The template toolchain and associated CMakePresets only support vcpkg as a package manager. Preset support for other package managers like Conan may be added in future.
  #### Documentation Limitations
  The entire project's documentation will currently regenerate every time the project is built. 
  This is because the documentation generation logic in docs/CMakeLists.txt uses wildcards (`*.h` `*.cpp`) to pick files to document, which can't be used with the cmake [doxygen_add_docs](https://cmake.org/cmake/help/latest/module/FindDoxygen.html#command:doxygen_add_docs "doxygen_add_docs cmake documentation") USE_STAMP_FILE arguement that ensures documentation is only regenerated for source files that are newer than their corresponding documentation.

  If using this project as a template, consider explicitly setting all paths to files being documented in a [doxygen_add_docs](https://cmake.org/cmake/help/latest/module/FindDoxygen.html#command:doxygen_add_docs "doxygen_add_docs cmake documentation") call to reduce build time. For more information on how CMake integrates with doxygen, check out CMake's [FindDoxygen Module Documentation](https://cmake.org/cmake/help/latest/module/FindDoxygen.html  "Documentation on the Module integrating doxygen into CMake")

  To suppress the doxygen output information when building, set the `DOXYGEN_QUIET` variable to `ON` in [`docs/CMakeLists.txt`](/docs/CMakeLists.txt).

  **Installing the Documentation**

  The documentation must have been built before installing, otherwise there may be errors during installation as cmake tries to install files that don't exist.

  #### Installation Limitations
  As the calculator library isn't intended for use in other projects, the install logic only copies build artifacts to an install folder as a cleanup step: making it easier to see what's actually been made.

  This installs each file individually, and breaks the target model of CMake: ensuring no target can be recreated using the find_package module in other C++ projects.

  ### Executable Limitations
  The executable is only meant to be a basic calculator, and so can only do these basic operations on 2 numbers/operands:
  * Addition
  * Subtraction
  * Multiplication
  * Division

  It is only intended for use showing the test capabilities of this toolchain and **should not** be used in other programs, projects or executables.

  Similarly, the test suite only includes basic unit tests, and doesn't test the full behaviour of the calculator. Even if it passes all tests, there is **no guarantee** the calculator will work as intended across the entire double number range, or that all potentially error causing behaviour has been tested in the test excecutable.

  #### **Exception Handling in the Division Function**
  The division function checks if the user has tried to divide by zero, if the denominator is zero, the function throws an `invalid argument` exception.
  
  > [!warning]
  > This is *not* a great way to handle dividing by zero in a division function - as it places responsibility on the **user** to ensure a valid catch statement is present in the code, and wrap function calls that may try to divide by zero in a try statement. Similarly, the handler in use is very simple: **only** telling users an exception occurred and doing *nothing* to handle it or provide a return value for the divide function.
  > However, the developers have kept this as throwing exceptions inform users that an error has occurred more explicitly than print statements alone, *immediately* stopping the program flow to print an error message instead of returning a pre-determined value which could cause undefined behaviour when referenced later in the main program.

## Contributing
  As a template for future projects, this project isn't accepting contributions at this time, however, if you feel like this template could be extended in any way or has missed any important parts, please get in contact so it can be updated.

  See [CONTRIBUTING.md](/CONTRIBUTING.md "Link to this project's contributing guidelines") for more details.
## License
This Project is licensed under the MIT License, a copy of which which can be found in the [LICENSE.txt](LICENSE.txt) in the root directory of the project, while the readme is modified from Deeshan Sharmas `readme-template` project and is licensed under the MIT License found in the [LICENSE.txt](Licenses/LICENSE.txt) found in the Licenses folder. 

## Toolchain Software Resources
### CMake Tools Extension
1. [CMake Tools Docs](https://github.com/microsoft/vscode-cmake-tools/blob/HEAD/docs/README.md)
  * These docs are *incredibly helpful*, and provide guides on most usage scenarios, including how to set up and use CMake presets in the extension for config, build, testing, etc.

### CMake
1. [CMake Homepage](https://cmake.org/ "The CMake website homepage")
2. [Download CMake](https://cmake.org/download/ "Cmake can be downloaded from here")
3. [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html "The Latest official CMake tutorial from Kitware")
### MSVC
1. [Configure VS Code for Microsoft C++](https://code.visualstudio.com/docs/cpp/config-msvc "Configuring VS Code for C++")
2. [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools "Link to VS Extension Marketplace's page on CMake Tools")
### VCPKG
1. [Vcpkg Overview](https://learn.microsoft.com/en-us/vcpkg/get_started/overview "Microsoft Learn intro to vcpkg")
2. [Get started with vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/overview#get-started-with-vcpkg "Links to foundational vcpkg topics")
3. [Using vcpkg Offline](https://learn.microsoft.com/en-us/vcpkg/concepts/offline "Microsoft Learn's using vcpkg offline page")
4. [vcpkg Exporting Packages Tutorial](https://learn.microsoft.com/en-us/vcpkg/produce/export-compiled-dependencies "Microsoft Learn's Tutorial on exporting packages in vcpkg")
5. [Setting up vcpkg with CMake in VS Code](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode "Setting up vcpkg with CMake in VS Code")
### Git
1. [Git Homepage](https://git-scm.com/ "The official Git website")
2. [Download Git for Windows](https://git-scm.com/install/windows "Download git for windows here.") 
### Doxygen
1. [Doxygen Homepage](https://www.doxygen.nl/index.html "The official Doxygen website: Doxygen can be downloaded from here!")
2. [FindDoxygen Module Documentation](https://cmake.org/cmake/help/latest/module/FindDoxygen.html  "Documentation on the Module integrating doxygen into CMake")
### GTest 
1. [GTest Quick Start: CMake](https://google.github.io/googletest/quickstart-cmake.html)
2. [GoogleTest User's Guide](https://google.github.io/googletest/)


