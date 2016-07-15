#include "Pushover.h"

Pushover::Pushover(String token, String user) {
	_token = token;
	_user = user;
}
void Pushover::setMessage(String message) {
	_message = message;
}
void Pushover::setDevice(String device) {
	_device = device;
}
void Pushover::setTitle(String title) {
	_title = title;
}
void Pushover::setUrl(String url) {
	_url = url;
}
void Pushover::setUrlTitle(String url_title) {
	_url_title = url_title;
}
void Pushover::setPriority(int8_t priority) {
	_priority = priority;
}
void Pushover::setRetry(uint16_t retry) {
	_retry = retry;
}
void Pushover::setExpire(uint16_t expire) {
	_expire = expire;
}
void Pushover::setTimestamp(uint32_t timestamp) {
	_timestamp = timestamp;
}
void Pushover::setSound(String sound) {
	_sound = sound;
}
void Pushover::setTimeout(uint16_t timeout) {
	_timeout = timeout;
}
void Pushover::setHTML(boolean html) {
	_html = html;
}
boolean Pushover::send(void) {
	WiFiClientSecure client;
	if (!client.connect("api.pushover.net", 443)) {
		return false;
	}
	String post = String("token=")+_token+"&user="+_user+"&title="+_title+"&message="+_message+"&device="+_device+"&url="+_url+"&url_title="+_url_title+"&priority="+_priority+"&retry="+_retry+"&expire="+_expire+"&sound="+_sound;
	if (_timestamp != 0) post += String("&timestamp=")+_timestamp;
	if (_html == true) post += String("&html=1");
	String http = String("POST /1/messages.json HTTP/1.1\r\nHost: api.pushover.net\r\nConnection: close\r\nAccept: Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nContent-Length: ")+post.length()+"\r\n\r\n"+post;
	client.print(http);
	int timeout_at = millis() + _timeout;
	while (!client.available() && timeout_at - millis() < 0) {
		client.stop();
		return false;
	}
	String line;
	while (client.available() != 0) {
		if (client.read() == '{') break;
	}
	line = client.readStringUntil('\n');
	return line.indexOf("\"status\":1") != -1;
}
