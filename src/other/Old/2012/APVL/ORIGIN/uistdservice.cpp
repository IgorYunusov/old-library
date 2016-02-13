// UISTDSERVICE MODULE

#include "cht.h"

template<class _TX> void UIStdServiceModulePex1::UIStdServiceInterfaceUnit::REXIComing<_TX>::InitExperator
	(UIStdServiceModulePex1::UIStdDefine::_tag_UISTD_module_experator<_TX> &experator)
{
	AllocLinkedPer(experator->_Now);
	experator->_Tail = experator->_Now;
}

template<class _TX> void UIStdServiceModulePex1::UIStdServiceInterfaceUnit::REXIComing<_TX>::AllocLinkedPer
	(UIStdServiceModulePex1::UIStdDefine::_tag_UISTD_linked<_TX> &linked)
{
	linked = new UIStdDefine::_tag_UISTD_linked<_TX>;
}