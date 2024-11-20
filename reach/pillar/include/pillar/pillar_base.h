#pragma once

/// @brief Bootstraps a pillar application in an SDL window.
/// @param lifecycle_hook Collection of function pointers that are called throughout the engine's lifecycle
i32 pillar_base_bootstrap(struct PillarAppLifecycleHook* lifecycle_hook);