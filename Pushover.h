#include <WiFiClientSecure.h>

class Pushover {
	private:
		String _token;
		String _user;
		String _message;
		String _device;
		String _title;
		String _url;
		String _url_title;
		int8_t _priority = 0;
		uint16_t _retry;
		uint16_t _expire;
		uint32_t _timestamp = 0;
		boolean _html;
		uint16_t _timeout = 5000;
		String _sound;
	public:
		Pushover(String,String);
		void setMessage(String);
		void setDevice(String);
		void setTitle(String);
		void setUrl(String);
		void setUrlTitle(String);
		void setPriority(int8_t);
		void setRetry(uint16_t);
		void setExpire(uint16_t);
		void setTimestamp(uint32_t);
		void setSound(String);
		void setHTML(boolean);
		void setTimeout(uint16_t);
		boolean send(void);
};
