# Setup & Build instructions on Windows 10
see also [Paraview's Wiki](http://www.paraview.org/Wiki/ParaView:Build_And_Install)

## Preparation:
* Install [Qt 5.8](https://www.qt.io/download-open-source) (both 32 and 64 bit versions)
* Install [CMake 3.8](https://cmake.org/download/)
* Install [Visual Studio 2015 Community](https://drive.google.com/open?id=0BzDYQBRp4j3nZS04R0NKdmVJbFE)
* Take ParaView from our [repo](https://github.com/vrcranfield/vr)
	* `git clone https://github.com/vrcranfield/vr`

## CMake:
* Set source to `Paraview/src/`, dest to `Paraview/src/build/` (**note that `build` is INSIDE `src`**)
* Set Generator to `Visual Studio 14 2015 Win64`
* Tick “Advanced” box
* Run Configure (**TODO** Check if `PARAVIEW_USE_OPENVR` is ON)
	* Set `OPENVR_ROOT_DIR` to `[Paraview]/src/OpenVR/` (replace `[Paraview]` with path to repo)
	* Set `OPENVR_HEADERS_ROOT_DIR` to `[Paraview]/src/OpenVR/headers` (replace `[Paraview]` with path to repo)
	* Set `OPENVR_LIBRARY_TEMP` to `[Paraview]/src/OpenVR/lib/win64/openvr_api.lib
* Run Configure
	* Set `SDL2MAIN_LIBRARY` to `[Paraview]/src/SDL2/lib/x64/SDL2main.lib`
	* Set `SDL2_INCLUDE_DIR` to `[Paraview]/src/SDL2/include`
	* Set `SDL2_LIBRARY_TEMP` to `[Paraview]/src/SDL2/lib/x64/SDL2.lib`
* Run Configure
* Run Generate

## Pre-Visual Studio:
* Append `C:\Qt\5.8\msvc2015_64\bin` to `PATH` System Environment Variable
* Run `cpDependencies.bat` and check that it’s copying everything
* Click “Open Project in VS” in CMake

## Visual Studio:
* Install Qt Visual Studio Tools from Extensions and Updates. Restart VS as requested
* Wait for Visual Studio to load and parse everything. 
* Build > Build Solution
* *Go grab a beer. It’s gonna take a while.*

## Run:
* Run Paraview (`Paraview/build/bin/Debug/Paraview.exe`)
* **BOOM DONE.**

# TODO LIST
* Fix CMake files so that we don't need `cpDependencies.bat` anymore