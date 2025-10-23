project "LineWeaverTest"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir (outputdir .. "/%{prj.name}")
	objdir (outputdir .. "/%{prj.name}/intermediates")

	includedirs {
		"%{wks.location}/LineWeaver/include"
	}
	
	links {
		"LineWeaver"
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