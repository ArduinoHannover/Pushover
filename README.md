# Pushover
Pushover Library for ESP8266

## Usage
The library offers almost all functions.

Initialize a new Pushover: `Pushover pushover = Pushover("myAppToken","myUserToken");`

Then you can call the setters and if you're done, just call `pushover.send()` which will return true on success.

### Setters
```
void setMessage(String); //required. otherwise it makes no sense, does it?
void setDevice(String); //broadcast to every device! do you really want to set this? ;-)
void setTitle(String); //what it's all about. otherwise app name
void setUrl(String); //oh, you want to open something! no call, no link
void setUrlTitle(String); //if you like to have something different than "Open URL"
void setPriority(int8_t); //-2, -1, 0 (default) 1 and 2
void setRetry(uint16_t); //retry in seconds, must be set with priority of 2
void setExpire(uint16_t); //timeout for message in seconds, must be set with priority of 2
void setTimestamp(uint32_t); //unix timestamp, if not set, it will be the time the message was received
void setSound(String); //pick a nice sound from the list
void setHTML(boolean); //is your message html formatted?
```

There is also a setter for the connection timeout (ms): `setTimeout(uint16_t)`.
