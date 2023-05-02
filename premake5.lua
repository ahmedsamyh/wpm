workspace "wpm"
    configurations {"Debug", "Release"}
    location "build"

project "wpm"
    kind "ConsoleApp"
    language "C++"
    architecture "x64"
    cppdialect "c++latest"
    staticruntime "On"
    targetdir "bin/%{cfg.buildcfg}"

files {"src/**.cpp"}
includedirs {"include"}

defines {"SFML_STATIC"}

-- MoGE_SFML --
links {"lib/%{cfg.buildcfg}/MoGE_SFML.lib"}
-- MoUI_SFML --
links {"lib/%{cfg.buildcfg}/MoUI_SFML.lib"}

-- sfml deps --
links {"lib/flac.lib"}
links {"lib/freetype.lib"}
links {"lib/ogg.lib"}
links {"lib/openal32.lib"}
links {"lib/vorbisenc.lib"}
links {"lib/vorbisfile.lib"}
links {"lib/vorbis.lib"}
links {"opengl32.lib"}
links {"winmm.lib"}
links {"gdi32.lib"}
links {"ws2_32.lib"}

filter "configurations:Debug"
    runtime "Debug"
    defines {"DEBUG"}
    symbols "On"
    links {"lib/Debug/sfml-audio-s-d.lib"}
    links {"lib/Debug/sfml-graphics-s-d.lib"}
    links {"lib/Debug/sfml-network-s-d.lib"}
    links {"lib/Debug/sfml-system-s-d.lib"}
    links {"lib/Debug/sfml-window-s-d.lib"}
    
filter "configurations:Release"
    runtime "Release"
    defines {"NDEBUG"}
    optimize "On"
    links {"lib/Release/sfml-audio-s.lib"}
    links {"lib/Release/sfml-graphics-s.lib"}
    links {"lib/Release/sfml-network-s.lib"}
    links {"lib/Release/sfml-system-s.lib"}
    links {"lib/Release/sfml-window-s.lib"}

filter {}
----------------------------------------------------
