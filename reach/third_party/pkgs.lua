third_party = {
    pkgs = {},
}

-- package definitions

third_party.pkgs["SDL"] = {
    include = "%{wks.location}/third_party/SDL/3.16/include",
    libdir = "%{wks.location}/third_party/SDL/3.16/lib",
    dlldir = "%{wks.location}/third_party/SDL/3.16/dll",
    link = "SDL3.lib",
}