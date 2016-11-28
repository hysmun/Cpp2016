#ifndef __INVALIDCLASSEMENTEXCEPTION_H__
#define __INVALIDCLASSEMENTEXCEPTION_H__


class InvalidClassementException
{
	protected:
		char *msg;
		int setMsg(const char *tmp);
		
	public:
		//init
		InvalidClassementException()
		{msg = NULL;};
		InvalidClassementException(const char *tmp)
		{msg = NULL;setMsg(tmp);};
		
		InvalidClassementException(const InvalidClassementException &tmp);
		~InvalidClassementException();
		
		char *getMsg() const {return msg;};
		
};


#endif
