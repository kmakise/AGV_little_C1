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

class sensor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.IR0 = null;
      this.IR1 = null;
      this.USA = null;
      this.USB = null;
      this.USL = null;
      this.USR = null;
    }
    else {
      if (initObj.hasOwnProperty('IR0')) {
        this.IR0 = initObj.IR0
      }
      else {
        this.IR0 = 0;
      }
      if (initObj.hasOwnProperty('IR1')) {
        this.IR1 = initObj.IR1
      }
      else {
        this.IR1 = 0;
      }
      if (initObj.hasOwnProperty('USA')) {
        this.USA = initObj.USA
      }
      else {
        this.USA = 0;
      }
      if (initObj.hasOwnProperty('USB')) {
        this.USB = initObj.USB
      }
      else {
        this.USB = 0;
      }
      if (initObj.hasOwnProperty('USL')) {
        this.USL = initObj.USL
      }
      else {
        this.USL = 0;
      }
      if (initObj.hasOwnProperty('USR')) {
        this.USR = initObj.USR
      }
      else {
        this.USR = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type sensor
    // Serialize message field [IR0]
    bufferOffset = _serializer.int32(obj.IR0, buffer, bufferOffset);
    // Serialize message field [IR1]
    bufferOffset = _serializer.int32(obj.IR1, buffer, bufferOffset);
    // Serialize message field [USA]
    bufferOffset = _serializer.int32(obj.USA, buffer, bufferOffset);
    // Serialize message field [USB]
    bufferOffset = _serializer.int32(obj.USB, buffer, bufferOffset);
    // Serialize message field [USL]
    bufferOffset = _serializer.int32(obj.USL, buffer, bufferOffset);
    // Serialize message field [USR]
    bufferOffset = _serializer.int32(obj.USR, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type sensor
    let len;
    let data = new sensor(null);
    // Deserialize message field [IR0]
    data.IR0 = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [IR1]
    data.IR1 = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [USA]
    data.USA = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [USB]
    data.USB = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [USL]
    data.USL = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [USR]
    data.USR = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simple_navigation_goals/sensor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7b2fc253ad368634d89fd7b84900def5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 IR0
    int32 IR1
    int32 USA
    int32 USB
    int32 USL
    int32 USR
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new sensor(null);
    if (msg.IR0 !== undefined) {
      resolved.IR0 = msg.IR0;
    }
    else {
      resolved.IR0 = 0
    }

    if (msg.IR1 !== undefined) {
      resolved.IR1 = msg.IR1;
    }
    else {
      resolved.IR1 = 0
    }

    if (msg.USA !== undefined) {
      resolved.USA = msg.USA;
    }
    else {
      resolved.USA = 0
    }

    if (msg.USB !== undefined) {
      resolved.USB = msg.USB;
    }
    else {
      resolved.USB = 0
    }

    if (msg.USL !== undefined) {
      resolved.USL = msg.USL;
    }
    else {
      resolved.USL = 0
    }

    if (msg.USR !== undefined) {
      resolved.USR = msg.USR;
    }
    else {
      resolved.USR = 0
    }

    return resolved;
    }
};

module.exports = sensor;
