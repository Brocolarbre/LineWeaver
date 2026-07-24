project "LineWeaverTest"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir (outputdir .. "/%{prj.name}")
	objdir (outputdir .. "/%{prj.name}/intermediates")

	includedirs {
		"%{wks.location}/LineWeaver/include"
	}
	
	links {
		"LineWeaver"
	}
	
	filter "options:shared-library"
		disablewarnings {
			"4251",
			"4275"
		}
		
	filter "not options:shared-library"
		defines {
			"LINEWEAVER_STATIC"
		}
	
	filter {}

	files {
		"src/**.hpp",
		"src/**.cpp"
	}