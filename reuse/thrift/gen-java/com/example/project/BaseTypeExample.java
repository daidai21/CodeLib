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
public class BaseTypeExample implements org.apache.thrift.TBase<BaseTypeExample, BaseTypeExample._Fields>, java.io.Serializable, Cloneable, Comparable<BaseTypeExample> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("BaseTypeExample");

  private static final org.apache.thrift.protocol.TField BOOL_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("bool_type", org.apache.thrift.protocol.TType.BOOL, (short)1);
  private static final org.apache.thrift.protocol.TField BYTE_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("byte_type", org.apache.thrift.protocol.TType.BYTE, (short)2);
  private static final org.apache.thrift.protocol.TField I16_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("i16_type", org.apache.thrift.protocol.TType.I16, (short)3);
  private static final org.apache.thrift.protocol.TField I32_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("i32_type", org.apache.thrift.protocol.TType.I32, (short)4);
  private static final org.apache.thrift.protocol.TField I64_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("i64_type", org.apache.thrift.protocol.TType.I64, (short)5);
  private static final org.apache.thrift.protocol.TField DOUBLE_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("double_type", org.apache.thrift.protocol.TType.DOUBLE, (short)6);
  private static final org.apache.thrift.protocol.TField STRING_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("string_type", org.apache.thrift.protocol.TType.STRING, (short)7);

  private static final Map<Class<? extends IScheme>, SchemeFactory> schemes = new HashMap<Class<? extends IScheme>, SchemeFactory>();
  static {
    schemes.put(StandardScheme.class, new BaseTypeExampleStandardSchemeFactory());
    schemes.put(TupleScheme.class, new BaseTypeExampleTupleSchemeFactory());
  }

  public boolean bool_type; // optional
  public byte byte_type; // optional
  public short i16_type; // optional
  public int i32_type; // optional
  public long i64_type; // optional
  public double double_type; // optional
  public String string_type; // optional

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    BOOL_TYPE((short)1, "bool_type"),
    BYTE_TYPE((short)2, "byte_type"),
    I16_TYPE((short)3, "i16_type"),
    I32_TYPE((short)4, "i32_type"),
    I64_TYPE((short)5, "i64_type"),
    DOUBLE_TYPE((short)6, "double_type"),
    STRING_TYPE((short)7, "string_type");

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
        case 1: // BOOL_TYPE
          return BOOL_TYPE;
        case 2: // BYTE_TYPE
          return BYTE_TYPE;
        case 3: // I16_TYPE
          return I16_TYPE;
        case 4: // I32_TYPE
          return I32_TYPE;
        case 5: // I64_TYPE
          return I64_TYPE;
        case 6: // DOUBLE_TYPE
          return DOUBLE_TYPE;
        case 7: // STRING_TYPE
          return STRING_TYPE;
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
  private static final int __BOOL_TYPE_ISSET_ID = 0;
  private static final int __BYTE_TYPE_ISSET_ID = 1;
  private static final int __I16_TYPE_ISSET_ID = 2;
  private static final int __I32_TYPE_ISSET_ID = 3;
  private static final int __I64_TYPE_ISSET_ID = 4;
  private static final int __DOUBLE_TYPE_ISSET_ID = 5;
  private byte __isset_bitfield = 0;
  private static final _Fields optionals[] = {_Fields.BOOL_TYPE,_Fields.BYTE_TYPE,_Fields.I16_TYPE,_Fields.I32_TYPE,_Fields.I64_TYPE,_Fields.DOUBLE_TYPE,_Fields.STRING_TYPE};
  public static final Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.BOOL_TYPE, new org.apache.thrift.meta_data.FieldMetaData("bool_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.BOOL)));
    tmpMap.put(_Fields.BYTE_TYPE, new org.apache.thrift.meta_data.FieldMetaData("byte_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.BYTE)));
    tmpMap.put(_Fields.I16_TYPE, new org.apache.thrift.meta_data.FieldMetaData("i16_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I16)));
    tmpMap.put(_Fields.I32_TYPE, new org.apache.thrift.meta_data.FieldMetaData("i32_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.I64_TYPE, new org.apache.thrift.meta_data.FieldMetaData("i64_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    tmpMap.put(_Fields.DOUBLE_TYPE, new org.apache.thrift.meta_data.FieldMetaData("double_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.DOUBLE)));
    tmpMap.put(_Fields.STRING_TYPE, new org.apache.thrift.meta_data.FieldMetaData("string_type", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(BaseTypeExample.class, metaDataMap);
  }

  public BaseTypeExample() {
    this.bool_type = false;

  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public BaseTypeExample(BaseTypeExample other) {
    __isset_bitfield = other.__isset_bitfield;
    this.bool_type = other.bool_type;
    this.byte_type = other.byte_type;
    this.i16_type = other.i16_type;
    this.i32_type = other.i32_type;
    this.i64_type = other.i64_type;
    this.double_type = other.double_type;
    if (other.isSetString_type()) {
      this.string_type = other.string_type;
    }
  }

  public BaseTypeExample deepCopy() {
    return new BaseTypeExample(this);
  }

  @Override
  public void clear() {
    this.bool_type = false;

    setByte_typeIsSet(false);
    this.byte_type = 0;
    setI16_typeIsSet(false);
    this.i16_type = 0;
    setI32_typeIsSet(false);
    this.i32_type = 0;
    setI64_typeIsSet(false);
    this.i64_type = 0;
    setDouble_typeIsSet(false);
    this.double_type = 0.0;
    this.string_type = null;
  }

  public boolean isBool_type() {
    return this.bool_type;
  }

  public BaseTypeExample setBool_type(boolean bool_type) {
    this.bool_type = bool_type;
    setBool_typeIsSet(true);
    return this;
  }

  public void unsetBool_type() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __BOOL_TYPE_ISSET_ID);
  }

  /** Returns true if field bool_type is set (has been assigned a value) and false otherwise */
  public boolean isSetBool_type() {
    return EncodingUtils.testBit(__isset_bitfield, __BOOL_TYPE_ISSET_ID);
  }

  public void setBool_typeIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __BOOL_TYPE_ISSET_ID, value);
  }

  public byte getByte_type() {
    return this.byte_type;
  }

  public BaseTypeExample setByte_type(byte byte_type) {
    this.byte_type = byte_type;
    setByte_typeIsSet(true);
    return this;
  }

  public void unsetByte_type() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __BYTE_TYPE_ISSET_ID);
  }

  /** Returns true if field byte_type is set (has been assigned a value) and false otherwise */
  public boolean isSetByte_type() {
    return EncodingUtils.testBit(__isset_bitfield, __BYTE_TYPE_ISSET_ID);
  }

  public void setByte_typeIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __BYTE_TYPE_ISSET_ID, value);
  }

  public short getI16_type() {
    return this.i16_type;
  }

  public BaseTypeExample setI16_type(short i16_type) {
    this.i16_type = i16_type;
    setI16_typeIsSet(true);
    return this;
  }

  public void unsetI16_type() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __I16_TYPE_ISSET_ID);
  }

  /** Returns true if field i16_type is set (has been assigned a value) and false otherwise */
  public boolean isSetI16_type() {
    return EncodingUtils.testBit(__isset_bitfield, __I16_TYPE_ISSET_ID);
  }

  public void setI16_typeIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __I16_TYPE_ISSET_ID, value);
  }

  public int getI32_type() {
    return this.i32_type;
  }

  public BaseTypeExample setI32_type(int i32_type) {
    this.i32_type = i32_type;
    setI32_typeIsSet(true);
    return this;
  }

  public void unsetI32_type() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __I32_TYPE_ISSET_ID);
  }

  /** Returns true if field i32_type is set (has been assigned a value) and false otherwise */
  public boolean isSetI32_type() {
    return EncodingUtils.testBit(__isset_bitfield, __I32_TYPE_ISSET_ID);
  }

  public void setI32_typeIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __I32_TYPE_ISSET_ID, value);
  }

  public long getI64_type() {
    return this.i64_type;
  }

  public BaseTypeExample setI64_type(long i64_type) {
    this.i64_type = i64_type;
    setI64_typeIsSet(true);
    return this;
  }

  public void unsetI64_type() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __I64_TYPE_ISSET_ID);
  }

  /** Returns true if field i64_type is set (has been assigned a value) and false otherwise */
  public boolean isSetI64_type() {
    return EncodingUtils.testBit(__isset_bitfield, __I64_TYPE_ISSET_ID);
  }

  public void setI64_typeIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __I64_TYPE_ISSET_ID, value);
  }

  public double getDouble_type() {
    return this.double_type;
  }

  public BaseTypeExample setDouble_type(double double_type) {
    this.double_type = double_type;
    setDouble_typeIsSet(true);
    return this;
  }

  public void unsetDouble_type() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __DOUBLE_TYPE_ISSET_ID);
  }

  /** Returns true if field double_type is set (has been assigned a value) and false otherwise */
  public boolean isSetDouble_type() {
    return EncodingUtils.testBit(__isset_bitfield, __DOUBLE_TYPE_ISSET_ID);
  }

  public void setDouble_typeIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __DOUBLE_TYPE_ISSET_ID, value);
  }

  public String getString_type() {
    return this.string_type;
  }

  public BaseTypeExample setString_type(String string_type) {
    this.string_type = string_type;
    return this;
  }

  public void unsetString_type() {
    this.string_type = null;
  }

  /** Returns true if field string_type is set (has been assigned a value) and false otherwise */
  public boolean isSetString_type() {
    return this.string_type != null;
  }

  public void setString_typeIsSet(boolean value) {
    if (!value) {
      this.string_type = null;
    }
  }

  public void setFieldValue(_Fields field, Object value) {
    switch (field) {
    case BOOL_TYPE:
      if (value == null) {
        unsetBool_type();
      } else {
        setBool_type((Boolean)value);
      }
      break;

    case BYTE_TYPE:
      if (value == null) {
        unsetByte_type();
      } else {
        setByte_type((Byte)value);
      }
      break;

    case I16_TYPE:
      if (value == null) {
        unsetI16_type();
      } else {
        setI16_type((Short)value);
      }
      break;

    case I32_TYPE:
      if (value == null) {
        unsetI32_type();
      } else {
        setI32_type((Integer)value);
      }
      break;

    case I64_TYPE:
      if (value == null) {
        unsetI64_type();
      } else {
        setI64_type((Long)value);
      }
      break;

    case DOUBLE_TYPE:
      if (value == null) {
        unsetDouble_type();
      } else {
        setDouble_type((Double)value);
      }
      break;

    case STRING_TYPE:
      if (value == null) {
        unsetString_type();
      } else {
        setString_type((String)value);
      }
      break;

    }
  }

  public Object getFieldValue(_Fields field) {
    switch (field) {
    case BOOL_TYPE:
      return Boolean.valueOf(isBool_type());

    case BYTE_TYPE:
      return Byte.valueOf(getByte_type());

    case I16_TYPE:
      return Short.valueOf(getI16_type());

    case I32_TYPE:
      return Integer.valueOf(getI32_type());

    case I64_TYPE:
      return Long.valueOf(getI64_type());

    case DOUBLE_TYPE:
      return Double.valueOf(getDouble_type());

    case STRING_TYPE:
      return getString_type();

    }
    throw new IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new IllegalArgumentException();
    }

    switch (field) {
    case BOOL_TYPE:
      return isSetBool_type();
    case BYTE_TYPE:
      return isSetByte_type();
    case I16_TYPE:
      return isSetI16_type();
    case I32_TYPE:
      return isSetI32_type();
    case I64_TYPE:
      return isSetI64_type();
    case DOUBLE_TYPE:
      return isSetDouble_type();
    case STRING_TYPE:
      return isSetString_type();
    }
    throw new IllegalStateException();
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof BaseTypeExample)
      return this.equals((BaseTypeExample)that);
    return false;
  }

  public boolean equals(BaseTypeExample that) {
    if (that == null)
      return false;

    boolean this_present_bool_type = true && this.isSetBool_type();
    boolean that_present_bool_type = true && that.isSetBool_type();
    if (this_present_bool_type || that_present_bool_type) {
      if (!(this_present_bool_type && that_present_bool_type))
        return false;
      if (this.bool_type != that.bool_type)
        return false;
    }

    boolean this_present_byte_type = true && this.isSetByte_type();
    boolean that_present_byte_type = true && that.isSetByte_type();
    if (this_present_byte_type || that_present_byte_type) {
      if (!(this_present_byte_type && that_present_byte_type))
        return false;
      if (this.byte_type != that.byte_type)
        return false;
    }

    boolean this_present_i16_type = true && this.isSetI16_type();
    boolean that_present_i16_type = true && that.isSetI16_type();
    if (this_present_i16_type || that_present_i16_type) {
      if (!(this_present_i16_type && that_present_i16_type))
        return false;
      if (this.i16_type != that.i16_type)
        return false;
    }

    boolean this_present_i32_type = true && this.isSetI32_type();
    boolean that_present_i32_type = true && that.isSetI32_type();
    if (this_present_i32_type || that_present_i32_type) {
      if (!(this_present_i32_type && that_present_i32_type))
        return false;
      if (this.i32_type != that.i32_type)
        return false;
    }

    boolean this_present_i64_type = true && this.isSetI64_type();
    boolean that_present_i64_type = true && that.isSetI64_type();
    if (this_present_i64_type || that_present_i64_type) {
      if (!(this_present_i64_type && that_present_i64_type))
        return false;
      if (this.i64_type != that.i64_type)
        return false;
    }

    boolean this_present_double_type = true && this.isSetDouble_type();
    boolean that_present_double_type = true && that.isSetDouble_type();
    if (this_present_double_type || that_present_double_type) {
      if (!(this_present_double_type && that_present_double_type))
        return false;
      if (this.double_type != that.double_type)
        return false;
    }

    boolean this_present_string_type = true && this.isSetString_type();
    boolean that_present_string_type = true && that.isSetString_type();
    if (this_present_string_type || that_present_string_type) {
      if (!(this_present_string_type && that_present_string_type))
        return false;
      if (!this.string_type.equals(that.string_type))
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    List<Object> list = new ArrayList<Object>();

    boolean present_bool_type = true && (isSetBool_type());
    list.add(present_bool_type);
    if (present_bool_type)
      list.add(bool_type);

    boolean present_byte_type = true && (isSetByte_type());
    list.add(present_byte_type);
    if (present_byte_type)
      list.add(byte_type);

    boolean present_i16_type = true && (isSetI16_type());
    list.add(present_i16_type);
    if (present_i16_type)
      list.add(i16_type);

    boolean present_i32_type = true && (isSetI32_type());
    list.add(present_i32_type);
    if (present_i32_type)
      list.add(i32_type);

    boolean present_i64_type = true && (isSetI64_type());
    list.add(present_i64_type);
    if (present_i64_type)
      list.add(i64_type);

    boolean present_double_type = true && (isSetDouble_type());
    list.add(present_double_type);
    if (present_double_type)
      list.add(double_type);

    boolean present_string_type = true && (isSetString_type());
    list.add(present_string_type);
    if (present_string_type)
      list.add(string_type);

    return list.hashCode();
  }

  @Override
  public int compareTo(BaseTypeExample other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetBool_type()).compareTo(other.isSetBool_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetBool_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.bool_type, other.bool_type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetByte_type()).compareTo(other.isSetByte_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetByte_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.byte_type, other.byte_type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetI16_type()).compareTo(other.isSetI16_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetI16_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.i16_type, other.i16_type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetI32_type()).compareTo(other.isSetI32_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetI32_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.i32_type, other.i32_type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetI64_type()).compareTo(other.isSetI64_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetI64_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.i64_type, other.i64_type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetDouble_type()).compareTo(other.isSetDouble_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetDouble_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.double_type, other.double_type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetString_type()).compareTo(other.isSetString_type());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetString_type()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.string_type, other.string_type);
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
    StringBuilder sb = new StringBuilder("BaseTypeExample(");
    boolean first = true;

    if (isSetBool_type()) {
      sb.append("bool_type:");
      sb.append(this.bool_type);
      first = false;
    }
    if (isSetByte_type()) {
      if (!first) sb.append(", ");
      sb.append("byte_type:");
      sb.append(this.byte_type);
      first = false;
    }
    if (isSetI16_type()) {
      if (!first) sb.append(", ");
      sb.append("i16_type:");
      sb.append(this.i16_type);
      first = false;
    }
    if (isSetI32_type()) {
      if (!first) sb.append(", ");
      sb.append("i32_type:");
      sb.append(this.i32_type);
      first = false;
    }
    if (isSetI64_type()) {
      if (!first) sb.append(", ");
      sb.append("i64_type:");
      sb.append(this.i64_type);
      first = false;
    }
    if (isSetDouble_type()) {
      if (!first) sb.append(", ");
      sb.append("double_type:");
      sb.append(this.double_type);
      first = false;
    }
    if (isSetString_type()) {
      if (!first) sb.append(", ");
      sb.append("string_type:");
      if (this.string_type == null) {
        sb.append("null");
      } else {
        sb.append(this.string_type);
      }
      first = false;
    }
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
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

  private static class BaseTypeExampleStandardSchemeFactory implements SchemeFactory {
    public BaseTypeExampleStandardScheme getScheme() {
      return new BaseTypeExampleStandardScheme();
    }
  }

  private static class BaseTypeExampleStandardScheme extends StandardScheme<BaseTypeExample> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, BaseTypeExample struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // BOOL_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.BOOL) {
              struct.bool_type = iprot.readBool();
              struct.setBool_typeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // BYTE_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.BYTE) {
              struct.byte_type = iprot.readByte();
              struct.setByte_typeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // I16_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.I16) {
              struct.i16_type = iprot.readI16();
              struct.setI16_typeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // I32_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.i32_type = iprot.readI32();
              struct.setI32_typeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 5: // I64_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.i64_type = iprot.readI64();
              struct.setI64_typeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 6: // DOUBLE_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.DOUBLE) {
              struct.double_type = iprot.readDouble();
              struct.setDouble_typeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 7: // STRING_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.string_type = iprot.readString();
              struct.setString_typeIsSet(true);
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

    public void write(org.apache.thrift.protocol.TProtocol oprot, BaseTypeExample struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      if (struct.isSetBool_type()) {
        oprot.writeFieldBegin(BOOL_TYPE_FIELD_DESC);
        oprot.writeBool(struct.bool_type);
        oprot.writeFieldEnd();
      }
      if (struct.isSetByte_type()) {
        oprot.writeFieldBegin(BYTE_TYPE_FIELD_DESC);
        oprot.writeByte(struct.byte_type);
        oprot.writeFieldEnd();
      }
      if (struct.isSetI16_type()) {
        oprot.writeFieldBegin(I16_TYPE_FIELD_DESC);
        oprot.writeI16(struct.i16_type);
        oprot.writeFieldEnd();
      }
      if (struct.isSetI32_type()) {
        oprot.writeFieldBegin(I32_TYPE_FIELD_DESC);
        oprot.writeI32(struct.i32_type);
        oprot.writeFieldEnd();
      }
      if (struct.isSetI64_type()) {
        oprot.writeFieldBegin(I64_TYPE_FIELD_DESC);
        oprot.writeI64(struct.i64_type);
        oprot.writeFieldEnd();
      }
      if (struct.isSetDouble_type()) {
        oprot.writeFieldBegin(DOUBLE_TYPE_FIELD_DESC);
        oprot.writeDouble(struct.double_type);
        oprot.writeFieldEnd();
      }
      if (struct.string_type != null) {
        if (struct.isSetString_type()) {
          oprot.writeFieldBegin(STRING_TYPE_FIELD_DESC);
          oprot.writeString(struct.string_type);
          oprot.writeFieldEnd();
        }
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class BaseTypeExampleTupleSchemeFactory implements SchemeFactory {
    public BaseTypeExampleTupleScheme getScheme() {
      return new BaseTypeExampleTupleScheme();
    }
  }

  private static class BaseTypeExampleTupleScheme extends TupleScheme<BaseTypeExample> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, BaseTypeExample struct) throws org.apache.thrift.TException {
      TTupleProtocol oprot = (TTupleProtocol) prot;
      BitSet optionals = new BitSet();
      if (struct.isSetBool_type()) {
        optionals.set(0);
      }
      if (struct.isSetByte_type()) {
        optionals.set(1);
      }
      if (struct.isSetI16_type()) {
        optionals.set(2);
      }
      if (struct.isSetI32_type()) {
        optionals.set(3);
      }
      if (struct.isSetI64_type()) {
        optionals.set(4);
      }
      if (struct.isSetDouble_type()) {
        optionals.set(5);
      }
      if (struct.isSetString_type()) {
        optionals.set(6);
      }
      oprot.writeBitSet(optionals, 7);
      if (struct.isSetBool_type()) {
        oprot.writeBool(struct.bool_type);
      }
      if (struct.isSetByte_type()) {
        oprot.writeByte(struct.byte_type);
      }
      if (struct.isSetI16_type()) {
        oprot.writeI16(struct.i16_type);
      }
      if (struct.isSetI32_type()) {
        oprot.writeI32(struct.i32_type);
      }
      if (struct.isSetI64_type()) {
        oprot.writeI64(struct.i64_type);
      }
      if (struct.isSetDouble_type()) {
        oprot.writeDouble(struct.double_type);
      }
      if (struct.isSetString_type()) {
        oprot.writeString(struct.string_type);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, BaseTypeExample struct) throws org.apache.thrift.TException {
      TTupleProtocol iprot = (TTupleProtocol) prot;
      BitSet incoming = iprot.readBitSet(7);
      if (incoming.get(0)) {
        struct.bool_type = iprot.readBool();
        struct.setBool_typeIsSet(true);
      }
      if (incoming.get(1)) {
        struct.byte_type = iprot.readByte();
        struct.setByte_typeIsSet(true);
      }
      if (incoming.get(2)) {
        struct.i16_type = iprot.readI16();
        struct.setI16_typeIsSet(true);
      }
      if (incoming.get(3)) {
        struct.i32_type = iprot.readI32();
        struct.setI32_typeIsSet(true);
      }
      if (incoming.get(4)) {
        struct.i64_type = iprot.readI64();
        struct.setI64_typeIsSet(true);
      }
      if (incoming.get(5)) {
        struct.double_type = iprot.readDouble();
        struct.setDouble_typeIsSet(true);
      }
      if (incoming.get(6)) {
        struct.string_type = iprot.readString();
        struct.setString_typeIsSet(true);
      }
    }
  }

}

