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

class msg209 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.age = null;
      this.RXlinear = null;
      this.RYlinear = null;
      this.Rangular = null;
      this.xpose = null;
      this.ypose = null;
      this.zAngle = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0;
      }
      if (initObj.hasOwnProperty('age')) {
        this.age = initObj.age
      }
      else {
        this.age = 0;
      }
      if (initObj.hasOwnProperty('RXlinear')) {
        this.RXlinear = initObj.RXlinear
      }
      else {
        this.RXlinear = 0.0;
      }
      if (initObj.hasOwnProperty('RYlinear')) {
        this.RYlinear = initObj.RYlinear
      }
      else {
        this.RYlinear = 0.0;
      }
      if (initObj.hasOwnProperty('Rangular')) {
        this.Rangular = initObj.Rangular
      }
      else {
        this.Rangular = 0.0;
      }
      if (initObj.hasOwnProperty('xpose')) {
        this.xpose = initObj.xpose
      }
      else {
        this.xpose = 0.0;
      }
      if (initObj.hasOwnProperty('ypose')) {
        this.ypose = initObj.ypose
      }
      else {
        this.ypose = 0.0;
      }
      if (initObj.hasOwnProperty('zAngle')) {
        this.zAngle = initObj.zAngle
      }
      else {
        this.zAngle = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type msg209
    // Serialize message field [time]
    bufferOffset = _serializer.uint32(obj.time, buffer, bufferOffset);
    // Serialize message field [age]
    bufferOffset = _serializer.uint8(obj.age, buffer, bufferOffset);
    // Serialize message field [RXlinear]
    bufferOffset = _serializer.float64(obj.RXlinear, buffer, bufferOffset);
    // Serialize message field [RYlinear]
    bufferOffset = _serializer.float64(obj.RYlinear, buffer, bufferOffset);
    // Serialize message field [Rangular]
    bufferOffset = _serializer.float64(obj.Rangular, buffer, bufferOffset);
    // Serialize message field [xpose]
    bufferOffset = _serializer.float64(obj.xpose, buffer, bufferOffset);
    // Serialize message field [ypose]
    bufferOffset = _serializer.float64(obj.ypose, buffer, bufferOffset);
    // Serialize message field [zAngle]
    bufferOffset = _serializer.float32(obj.zAngle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type msg209
    let len;
    let data = new msg209(null);
    // Deserialize message field [time]
    data.time = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [age]
    data.age = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [RXlinear]
    data.RXlinear = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [RYlinear]
    data.RYlinear = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Rangular]
    data.Rangular = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [xpose]
    data.xpose = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ypose]
    data.ypose = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [zAngle]
    data.zAngle = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 49;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simple_navigation_goals/msg209';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a5f0e33b00a5cbe9ea65848687eaa24e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 time
    uint8 age
    
    float64 RXlinear
    float64 RYlinear
    float64 Rangular
    float64 xpose
    float64 ypose
    
    float32 zAngle
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new msg209(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0
    }

    if (msg.age !== undefined) {
      resolved.age = msg.age;
    }
    else {
      resolved.age = 0
    }

    if (msg.RXlinear !== undefined) {
      resolved.RXlinear = msg.RXlinear;
    }
    else {
      resolved.RXlinear = 0.0
    }

    if (msg.RYlinear !== undefined) {
      resolved.RYlinear = msg.RYlinear;
    }
    else {
      resolved.RYlinear = 0.0
    }

    if (msg.Rangular !== undefined) {
      resolved.Rangular = msg.Rangular;
    }
    else {
      resolved.Rangular = 0.0
    }

    if (msg.xpose !== undefined) {
      resolved.xpose = msg.xpose;
    }
    else {
      resolved.xpose = 0.0
    }

    if (msg.ypose !== undefined) {
      resolved.ypose = msg.ypose;
    }
    else {
      resolved.ypose = 0.0
    }

    if (msg.zAngle !== undefined) {
      resolved.zAngle = msg.zAngle;
    }
    else {
      resolved.zAngle = 0.0
    }

    return resolved;
    }
};

module.exports = msg209;
