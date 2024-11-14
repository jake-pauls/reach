#pragma once

#define DX_CALL(h_result) \
	if (FAILED(h_result)) \
	{ \
		RVERIFY(false, "DX_CALL failed, refer to DirectX11 trace for more information."); \
	} \

#define DX_CALL_SUCCEEDED(h_result) SUCCEEDED(h_result)

#define DX_CALL_FAILED(h_result) FAILED(h_result)
