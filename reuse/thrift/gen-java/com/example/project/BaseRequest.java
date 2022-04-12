/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.example.project;

import org.apache.thrift.scheme.IScheme;
import org.apache.thrift.scheme.SchemeFactory;
import org.apache.thrift.scheme.StandardScheme;

import org.apache.thrift.scheme.TupleScheme;
import org.apache.thrift.protocol.TTupleProtocol;
import org.apache.thrift.protocol.TProtocolException;
import org.apache.thrift.EncodingUtils;
import org.apache.thrift.TException;
import org.apache.thrift.async.AsyncMethodCallback;
import org.apache.thrift.server.AbstractNonblockingServer.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.EnumMap;
import java.util.Set;
import java.util.HashSet;
import java.util.EnumSet;
import java.util.Collections;
import java.util.BitSet;
import java.nio.ByteBuffer;
import java.util.Arrays;
import javax.annotation.Generated;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked"})
@Generated(value = "Autogenerated by Thrift Compiler (0.9.2)", date = "2022-4-12")
public class BaseRequest implements org.apache.thrift.TBase<BaseRequest, BaseRequest._Fields>, java.io.Serializable, Cloneable, Comparable<BaseRequest> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("BaseRequest");

  private static final org.apache.thrift.protocol.TField TRACE_ID_FIELD_DESC = new org.apache.thrift.protocol.TField("traceId", org.apache.thrift.protocol.TType.STRING, (short)1);
  private static final org.apache.thrift.protocol.TField PARAM_FIELD_DESC = new org.apache.thrift.protocol.TField("param", org.apache.thrift.protocol.TType.DOUBLE, (short)2);
  private static final org.apache.thrift.protocol.TField PARAM2_FIELD_DESC = new org.apache.thrift.protocol.TField("param2", org.apache.thrift.protocol.TType.I32, (short)3);
  private static final org.apache.thrift.protocol.TField USER_ID_FIELD_DESC = new org.apache.thrift.protocol.TField("userId", org.apache.thrift.protocol.TType.I64, (short)4);

  private static final Map<Class<? extends IScheme>, SchemeFactory> schemes = new HashMap<Class<? extends IScheme>, SchemeFactory>();
  static {
    schemes.put(StandardScheme.class, new BaseRequestStandardSchemeFactory());
    schemes.put(TupleScheme.class, new BaseRequestTupleSchemeFactory());
  }

  public String traceId; // required
  public double param; // optional
  /**
   * 
   * @see EnumExample
   */
  public EnumExample param2; // optional
  public long userId; // optional

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    TRACE_ID((short)1, "traceId"),
    PARAM((short)2, "param"),
    /**
     * 
     * @see EnumExample
     */
    PARAM2((short)3, "param2"),
    USER_ID((short)4, "userId");

    private static final Map<String, _Fields> byName = new HashMap<String, _Fields>();

    static {
      for (_Fields field : EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // TRACE_ID
          return TRACE_ID;
        case 2: // PARAM
          return PARAM;
        case 3: // PARAM2
          return PARAM2;
        case 4: // USER_ID
          return USER_ID;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    public static _Fields findByName(String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final String _fieldName;

    _Fields(short thriftId, String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  private static final int __PARAM_ISSET_ID = 0;
  private static final int __USERID_ISSET_ID = 1;
  private byte __isset_bitfield = 0;
  private static final _Fields optionals[] = {_Fields.PARAM,_Fields.PARAM2,_Fields.USER_ID};
  public static final Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.TRACE_ID, new org.apache.thrift.meta_data.FieldMetaData("traceId", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.PARAM, new org.apache.thrift.meta_data.FieldMetaData("param", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.DOUBLE)));
    tmpMap.put(_Fields.PARAM2, new org.apache.thrift.meta_data.FieldMetaData("param2", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.EnumMetaData(org.apache.thrift.protocol.TType.ENUM, EnumExample.class)));
    tmpMap.put(_Fields.USER_ID, new org.apache.thrift.meta_data.FieldMetaData("userId", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64        , "Long")));
    metaDataMap = Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(BaseRequest.class, metaDataMap);
  }

  public BaseRequest() {
    this.param2 = com.example.project.EnumExample.SUCCEED;

  }

  public BaseRequest(
    String traceId)
  {
    this();
    this.traceId = traceId;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public BaseRequest(BaseRequest other) {
    __isset_bitfield = other.__isset_bitfield;
    if (other.isSetTraceId()) {
      this.traceId = other.traceId;
    }
    this.param = other.param;
    if (other.isSetParam2()) {
      this.param2 = other.param2;
    }
    this.userId = other.userId;
  }

  public BaseRequest deepCopy() {
    return new BaseRequest(this);
  }

  @Override
  public void clear() {
    this.traceId = null;
    setParamIsSet(false);
    this.param = 0.0;
    this.param2 = com.example.project.EnumExample.SUCCEED;

    setUserIdIsSet(false);
    this.userId = 0;
  }

  public String getTraceId() {
    return this.traceId;
  }

  public BaseRequest setTraceId(String traceId) {
    this.traceId = traceId;
    return this;
  }

  public void unsetTraceId() {
    this.traceId = null;
  }

  /** Returns true if field traceId is set (has been assigned a value) and false otherwise */
  public boolean isSetTraceId() {
    return this.traceId != null;
  }

  public void setTraceIdIsSet(boolean value) {
    if (!value) {
      this.traceId = null;
    }
  }

  public double getParam() {
    return this.param;
  }

  public BaseRequest setParam(double param) {
    this.param = param;
    setParamIsSet(true);
    return this;
  }

  public void unsetParam() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __PARAM_ISSET_ID);
  }

  /** Returns true if field param is set (has been assigned a value) and false otherwise */
  public boolean isSetParam() {
    return EncodingUtils.testBit(__isset_bitfield, __PARAM_ISSET_ID);
  }

  public void setParamIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __PARAM_ISSET_ID, value);
  }

  /**
   * 
   * @see EnumExample
   */
  public EnumExample getParam2() {
    return this.param2;
  }

  /**
   * 
   * @see EnumExample
   */
  public BaseRequest setParam2(EnumExample param2) {
    this.param2 = param2;
    return this;
  }

  public void unsetParam2() {
    this.param2 = null;
  }

  /** Returns true if field param2 is set (has been assigned a value) and false otherwise */
  public boolean isSetParam2() {
    return this.param2 != null;
  }

  public void setParam2IsSet(boolean value) {
    if (!value) {
      this.param2 = null;
    }
  }

  public long getUserId() {
    return this.userId;
  }

  public BaseRequest setUserId(long userId) {
    this.userId = userId;
    setUserIdIsSet(true);
    return this;
  }

  public void unsetUserId() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __USERID_ISSET_ID);
  }

  /** Returns true if field userId is set (has been assigned a value) and false otherwise */
  public boolean isSetUserId() {
    return EncodingUtils.testBit(__isset_bitfield, __USERID_ISSET_ID);
  }

  public void setUserIdIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __USERID_ISSET_ID, value);
  }

  public void setFieldValue(_Fields field, Object value) {
    switch (field) {
    case TRACE_ID:
      if (value == null) {
        unsetTraceId();
      } else {
        setTraceId((String)value);
      }
      break;

    case PARAM:
      if (value == null) {
        unsetParam();
      } else {
        setParam((Double)value);
      }
      break;

    case PARAM2:
      if (value == null) {
        unsetParam2();
      } else {
        setParam2((EnumExample)value);
      }
      break;

    case USER_ID:
      if (value == null) {
        unsetUserId();
      } else {
        setUserId((Long)value);
      }
      break;

    }
  }

  public Object getFieldValue(_Fields field) {
    switch (field) {
    case TRACE_ID:
      return getTraceId();

    case PARAM:
      return Double.valueOf(getParam());

    case PARAM2:
      return getParam2();

    case USER_ID:
      return Long.valueOf(getUserId());

    }
    throw new IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new IllegalArgumentException();
    }

    switch (field) {
    case TRACE_ID:
      return isSetTraceId();
    case PARAM:
      return isSetParam();
    case PARAM2:
      return isSetParam2();
    case USER_ID:
      return isSetUserId();
    }
    throw new IllegalStateException();
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof BaseRequest)
      return this.equals((BaseRequest)that);
    return false;
  }

  public boolean equals(BaseRequest that) {
    if (that == null)
      return false;

    boolean this_present_traceId = true && this.isSetTraceId();
    boolean that_present_traceId = true && that.isSetTraceId();
    if (this_present_traceId || that_present_traceId) {
      if (!(this_present_traceId && that_present_traceId))
        return false;
      if (!this.traceId.equals(that.traceId))
        return false;
    }

    boolean this_present_param = true && this.isSetParam();
    boolean that_present_param = true && that.isSetParam();
    if (this_present_param || that_present_param) {
      if (!(this_present_param && that_present_param))
        return false;
      if (this.param != that.param)
        return false;
    }

    boolean this_present_param2 = true && this.isSetParam2();
    boolean that_present_param2 = true && that.isSetParam2();
    if (this_present_param2 || that_present_param2) {
      if (!(this_present_param2 && that_present_param2))
        return false;
      if (!this.param2.equals(that.param2))
        return false;
    }

    boolean this_present_userId = true && this.isSetUserId();
    boolean that_present_userId = true && that.isSetUserId();
    if (this_present_userId || that_present_userId) {
      if (!(this_present_userId && that_present_userId))
        return false;
      if (this.userId != that.userId)
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    List<Object> list = new ArrayList<Object>();

    boolean present_traceId = true && (isSetTraceId());
    list.add(present_traceId);
    if (present_traceId)
      list.add(traceId);

    boolean present_param = true && (isSetParam());
    list.add(present_param);
    if (present_param)
      list.add(param);

    boolean present_param2 = true && (isSetParam2());
    list.add(present_param2);
    if (present_param2)
      list.add(param2.getValue());

    boolean present_userId = true && (isSetUserId());
    list.add(present_userId);
    if (present_userId)
      list.add(userId);

    return list.hashCode();
  }

  @Override
  public int compareTo(BaseRequest other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetTraceId()).compareTo(other.isSetTraceId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetTraceId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.traceId, other.traceId);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetParam()).compareTo(other.isSetParam());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetParam()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.param, other.param);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetParam2()).compareTo(other.isSetParam2());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetParam2()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.param2, other.param2);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetUserId()).compareTo(other.isSetUserId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetUserId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.userId, other.userId);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    return 0;
  }

  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    schemes.get(iprot.getScheme()).getScheme().read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    schemes.get(oprot.getScheme()).getScheme().write(oprot, this);
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder("BaseRequest(");
    boolean first = true;

    sb.append("traceId:");
    if (this.traceId == null) {
      sb.append("null");
    } else {
      sb.append(this.traceId);
    }
    first = false;
    if (isSetParam()) {
      if (!first) sb.append(", ");
      sb.append("param:");
      sb.append(this.param);
      first = false;
    }
    if (isSetParam2()) {
      if (!first) sb.append(", ");
      sb.append("param2:");
      if (this.param2 == null) {
        sb.append("null");
      } else {
        sb.append(this.param2);
      }
      first = false;
    }
    if (isSetUserId()) {
      if (!first) sb.append(", ");
      sb.append("userId:");
      sb.append(this.userId);
      first = false;
    }
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    if (traceId == null) {
      throw new org.apache.thrift.protocol.TProtocolException("Required field 'traceId' was not present! Struct: " + toString());
    }
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, ClassNotFoundException {
    try {
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class BaseRequestStandardSchemeFactory implements SchemeFactory {
    public BaseRequestStandardScheme getScheme() {
      return new BaseRequestStandardScheme();
    }
  }

  private static class BaseRequestStandardScheme extends StandardScheme<BaseRequest> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, BaseRequest struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // TRACE_ID
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.traceId = iprot.readString();
              struct.setTraceIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // PARAM
            if (schemeField.type == org.apache.thrift.protocol.TType.DOUBLE) {
              struct.param = iprot.readDouble();
              struct.setParamIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // PARAM2
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.param2 = com.example.project.EnumExample.findByValue(iprot.readI32());
              struct.setParam2IsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // USER_ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.userId = iprot.readI64();
              struct.setUserIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, BaseRequest struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      if (struct.traceId != null) {
        oprot.writeFieldBegin(TRACE_ID_FIELD_DESC);
        oprot.writeString(struct.traceId);
        oprot.writeFieldEnd();
      }
      if (struct.isSetParam()) {
        oprot.writeFieldBegin(PARAM_FIELD_DESC);
        oprot.writeDouble(struct.param);
        oprot.writeFieldEnd();
      }
      if (struct.param2 != null) {
        if (struct.isSetParam2()) {
          oprot.writeFieldBegin(PARAM2_FIELD_DESC);
          oprot.writeI32(struct.param2.getValue());
          oprot.writeFieldEnd();
        }
      }
      if (struct.isSetUserId()) {
        oprot.writeFieldBegin(USER_ID_FIELD_DESC);
        oprot.writeI64(struct.userId);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class BaseRequestTupleSchemeFactory implements SchemeFactory {
    public BaseRequestTupleScheme getScheme() {
      return new BaseRequestTupleScheme();
    }
  }

  private static class BaseRequestTupleScheme extends TupleScheme<BaseRequest> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, BaseRequest struct) throws org.apache.thrift.TException {
      TTupleProtocol oprot = (TTupleProtocol) prot;
      oprot.writeString(struct.traceId);
      BitSet optionals = new BitSet();
      if (struct.isSetParam()) {
        optionals.set(0);
      }
      if (struct.isSetParam2()) {
        optionals.set(1);
      }
      if (struct.isSetUserId()) {
        optionals.set(2);
      }
      oprot.writeBitSet(optionals, 3);
      if (struct.isSetParam()) {
        oprot.writeDouble(struct.param);
      }
      if (struct.isSetParam2()) {
        oprot.writeI32(struct.param2.getValue());
      }
      if (struct.isSetUserId()) {
        oprot.writeI64(struct.userId);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, BaseRequest struct) throws org.apache.thrift.TException {
      TTupleProtocol iprot = (TTupleProtocol) prot;
      struct.traceId = iprot.readString();
      struct.setTraceIdIsSet(true);
      BitSet incoming = iprot.readBitSet(3);
      if (incoming.get(0)) {
        struct.param = iprot.readDouble();
        struct.setParamIsSet(true);
      }
      if (incoming.get(1)) {
        struct.param2 = com.example.project.EnumExample.findByValue(iprot.readI32());
        struct.setParam2IsSet(true);
      }
      if (incoming.get(2)) {
        struct.userId = iprot.readI64();
        struct.setUserIdIsSet(true);
      }
    }
  }

}

