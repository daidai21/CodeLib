/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.example.project;


import java.util.Map;
import java.util.HashMap;
import org.apache.thrift.TEnum;

public enum EnumExample implements org.apache.thrift.TEnum {
  SUCCEED(0),
  FAILED(1);

  private final int value;

  private EnumExample(int value) {
    this.value = value;
  }

  /**
   * Get the integer value of this enum value, as defined in the Thrift IDL.
   */
  public int getValue() {
    return value;
  }

  /**
   * Find a the enum type by its integer value, as defined in the Thrift IDL.
   * @return null if the value is not found.
   */
  public static EnumExample findByValue(int value) { 
    switch (value) {
      case 0:
        return SUCCEED;
      case 1:
        return FAILED;
      default:
        return null;
    }
  }
}
