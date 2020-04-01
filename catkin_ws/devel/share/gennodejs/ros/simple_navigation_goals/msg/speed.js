// Auto-generated. Do not edit!

// (in-package simple_navigation_goals.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class speed {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stop = null;
    }
    else {
      if (initObj.hasOwnProperty('stop')) {
        this.stop = initObj.stop
      }
      else {
        this.stop = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type speed
    // Serialize message field [stop]
    bufferOffset = _serializer.int32(obj.stop, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type speed
    let len;
    let data = new speed(null);
    // Deserialize message field [stop]
    data.stop = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simple_navigation_goals/speed';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e2327cd410f9df67fdb178d3542f8022';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 stop
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new speed(null);
    if (msg.stop !== undefined) {
      resolved.stop = msg.stop;
    }
    else {
      resolved.stop = 0
    }

    return resolved;
    }
};

module.exports = speed;
