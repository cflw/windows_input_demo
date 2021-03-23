#pragma once
#include <deque>
#include <cflw数学.h>
#include <cflw图形_d2d.h>
#include <cflw输入_win8.h>
#include <cflw时间.h>
namespace 数学 = cflw::数学;
namespace 二维 = cflw::图形::d2d;
namespace 输入w = cflw::输入::win8;
namespace 时间 = cflw::时间;
class C输入 {
public:
	enum E颜色 {
		e红,
		e绿,
		e蓝,
	};
	struct S轨迹点 {
		数学::S向量2 m坐标;
		E颜色 m颜色;
		时间::t时间点 m时间;
	};
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	void f消息(UINT, WPARAM, LPARAM);
	时间::C计帧器 m计帧器0;	//计算
	时间::C计帧器 m计帧器1;	//渲染
	二维::C二维 m二维;
	二维::tp画图形 m画图形;
	二维::tp画文本 m画文本;
	输入w::C输入 m输入;
	输入w::tp笔 m笔;
	std::vector<输入w::tp笔点> ma笔点;
};