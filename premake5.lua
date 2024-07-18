-- premake5.lua
workspace "Brainf"
   configurations { "Debug", "Release" }

project "brainf"
   kind "ConsoleApp"
   language "C++"
   targetdir "build/bin/%{cfg.buildcfg}"
   objdir "build/obj"

   files { "src/**.h", "src/**.cpp"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
