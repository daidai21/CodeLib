/* ****************************************************************************
 * File Name   : ring_buffer.hpp
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 日  9/13 13:53:40 2020
 *************************************************************************** */


/**
 * ring buffer
 * 
 * not support thread safe
 * 
 * TODO: support buf_size param init
 */
template<typename NodeType>
class RingBuffer {
 public:

  bool empty() {
    return this->head == this->tail;
  }

  bool full() {
    return (this->tail + 1) % this->buf_size == this->head;
  }

  bool put(NodeType node) {
    if (this->full()) {
      return false;
    }
    this->buf[this->tail] = node;
    this->tail = (this->tail + 1) % this->buf_size;
    return true;
  }

  NodeType get() {
    if (this->empty()) {
      return NULL;
    }
    NodeType result = this->buf[this->head];
    this->head = (this->head + 1) % this->buf_size;
    return result;
  }

  NodeType[] get_all() {
    if (this->empty()) {
      return NULL;
    }
    size_t copy_tail = this->tail;
    size_t node_count = this->head < copy_tail ?
                        copy_tail - this->head : 
                        this->buf_size - this->head + copyt_tail;
    NodeType[] result = new NodeType[node_count];
    if (this->head < copy_tail) {
      for (int i = this->head; i < copy_tail; ++i) {
        result[i - this->head] = this->buf[i];
      }
    } else {
      for (int i = this->head; i < this->buf_size; ++i) {
        result[i - this->head] = this->buf[i];
      }
      for (int i =0; i < copy_tail; ++i) {
        result[this->buf_size - this->head + i] = this->buf[i];
      }
    }
    this->head = copy_tail;
    return result;
  }

 private:
  size_t head = 0;
  size_t tail = 0;
  static size_t buf_size = 1024;
  NodeType[] buf = new NodeType[buf_size];
};
