workspace "Bamboo"
	architecture "x64"
	
	configurations
	{ 
		"Debug", 
        "Release",
        "Dist"
    }
    
local outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bamboo"
    location "Bamboo"
    kind "SharedLib"
    language "C++"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 
    }

    includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
	}
    
	filter "system:windows"
		cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
		defines 
		{ 
            "BB_PLATFORM_WINDOWS",
            "BAMBOO_BUILD_DLL",
		}

        -- postbuildcommands
        -- {
        --     ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        -- }
					
    filter "configurations:Debug"
        defines "BB_DEBUG"
        symbols "On"
                
    filter "configurations:Release"
        defines "BB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BB_DIST"
        optimize "On"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 
	}
    
	includedirs 
	{
        "Bamboo/vendor/spdlog/include",
        "Bamboo/src"
    }

    links 
    { 
        "Bamboo"
    }
	
	filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
		defines 
		{ 
            "BB_PLATFORM_WINDOWS",
		}

        postbuildcommands
        {
            ("{COPYFILE} ../bin/" .. outputdir .. "/Bamboo/Bamboo.dll %{cfg.targetdir}")
        }
    
    filter "configurations:Debug"
        defines "BB_DEBUG"
        symbols "On"
                
    filter "configurations:Release"
        defines "BB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BB_DIST"
        optimize "On"
 