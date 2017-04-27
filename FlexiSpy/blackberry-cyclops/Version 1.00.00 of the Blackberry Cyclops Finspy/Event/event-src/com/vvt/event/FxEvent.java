package com.vvt.event;

import net.rim.device.api.util.Persistable;
import com.vvt.event.constant.EventType;

public class FxEvent implements Persistable {
	
	private int eventId = 0;
	private EventType eventType = EventType.UNKNOWN;
	private long eventTime = 0;
	
	public long getEventTime() {
		return eventTime;
	}
	
	public int getEventId() {
		return eventId;
	}
	
	public EventType getEventType() {
		return eventType;
	}
	
	public long getObjectSize() {
		long size = 0;
		size += 4; // eventId
		size += 4; // eventType
		size += 8; // eventTime
		return size;
	}

	public void setEventTime(long eventTime) {
		this.eventTime = eventTime;
	}
	
	public void setEventId(int eventId) {
		this.eventId = eventId;
	}
	
	protected void setEventType(EventType eventType) {
		this.eventType = eventType;
	}
}