#pragma once

#ifdef VIEW_EXPORTS
#define VIEW_API __declspec(dllexport)
#else
#define VIEW_API __declspec(dllimport)
#endif