/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: response.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "response.pb-c.h"
void   response_header__init
                     (ResponseHeader         *message)
{
  static const ResponseHeader init_value = RESPONSE_HEADER__INIT;
  *message = init_value;
}
size_t response_header__get_packed_size
                     (const ResponseHeader *message)
{
  assert(message->base.descriptor == &response_header__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t response_header__pack
                     (const ResponseHeader *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &response_header__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t response_header__pack_to_buffer
                     (const ResponseHeader *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &response_header__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
ResponseHeader *
       response_header__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (ResponseHeader *)
     protobuf_c_message_unpack (&response_header__descriptor,
                                allocator, len, data);
}
void   response_header__free_unpacked
                     (ResponseHeader *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &response_header__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   exfiltration_response__init
                     (ExfiltrationResponse         *message)
{
  static const ExfiltrationResponse init_value = EXFILTRATION_RESPONSE__INIT;
  *message = init_value;
}
size_t exfiltration_response__get_packed_size
                     (const ExfiltrationResponse *message)
{
  assert(message->base.descriptor == &exfiltration_response__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t exfiltration_response__pack
                     (const ExfiltrationResponse *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &exfiltration_response__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t exfiltration_response__pack_to_buffer
                     (const ExfiltrationResponse *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &exfiltration_response__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
ExfiltrationResponse *
       exfiltration_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (ExfiltrationResponse *)
     protobuf_c_message_unpack (&exfiltration_response__descriptor,
                                allocator, len, data);
}
void   exfiltration_response__free_unpacked
                     (ExfiltrationResponse *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &exfiltration_response__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   infiltration_response__init
                     (InfiltrationResponse         *message)
{
  static const InfiltrationResponse init_value = INFILTRATION_RESPONSE__INIT;
  *message = init_value;
}
size_t infiltration_response__get_packed_size
                     (const InfiltrationResponse *message)
{
  assert(message->base.descriptor == &infiltration_response__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t infiltration_response__pack
                     (const InfiltrationResponse *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &infiltration_response__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t infiltration_response__pack_to_buffer
                     (const InfiltrationResponse *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &infiltration_response__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
InfiltrationResponse *
       infiltration_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (InfiltrationResponse *)
     protobuf_c_message_unpack (&infiltration_response__descriptor,
                                allocator, len, data);
}
void   infiltration_response__free_unpacked
                     (InfiltrationResponse *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &infiltration_response__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   read_dir_response__dir_entry__init
                     (ReadDirResponse__DirEntry         *message)
{
  static const ReadDirResponse__DirEntry init_value = READ_DIR_RESPONSE__DIR_ENTRY__INIT;
  *message = init_value;
}
void   read_dir_response__init
                     (ReadDirResponse         *message)
{
  static const ReadDirResponse init_value = READ_DIR_RESPONSE__INIT;
  *message = init_value;
}
size_t read_dir_response__get_packed_size
                     (const ReadDirResponse *message)
{
  assert(message->base.descriptor == &read_dir_response__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t read_dir_response__pack
                     (const ReadDirResponse *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &read_dir_response__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t read_dir_response__pack_to_buffer
                     (const ReadDirResponse *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &read_dir_response__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
ReadDirResponse *
       read_dir_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (ReadDirResponse *)
     protobuf_c_message_unpack (&read_dir_response__descriptor,
                                allocator, len, data);
}
void   read_dir_response__free_unpacked
                     (ReadDirResponse *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &read_dir_response__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   suicide_response__init
                     (SuicideResponse         *message)
{
  static const SuicideResponse init_value = SUICIDE_RESPONSE__INIT;
  *message = init_value;
}
size_t suicide_response__get_packed_size
                     (const SuicideResponse *message)
{
  assert(message->base.descriptor == &suicide_response__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t suicide_response__pack
                     (const SuicideResponse *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &suicide_response__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t suicide_response__pack_to_buffer
                     (const SuicideResponse *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &suicide_response__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
SuicideResponse *
       suicide_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (SuicideResponse *)
     protobuf_c_message_unpack (&suicide_response__descriptor,
                                allocator, len, data);
}
void   suicide_response__free_unpacked
                     (SuicideResponse *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &suicide_response__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor response_header__field_descriptors[2] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(ResponseHeader, status),
    &status__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "size",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(ResponseHeader, size),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned response_header__field_indices_by_name[] = {
  1,   /* field[1] = size */
  0,   /* field[0] = status */
};
static const ProtobufCIntRange response_header__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor response_header__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "responseHeader",
  "ResponseHeader",
  "ResponseHeader",
  "",
  sizeof(ResponseHeader),
  2,
  response_header__field_descriptors,
  response_header__field_indices_by_name,
  1,  response_header__number_ranges,
  (ProtobufCMessageInit) response_header__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor exfiltration_response__field_descriptors[1] =
{
  {
    "content",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(ExfiltrationResponse, content),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned exfiltration_response__field_indices_by_name[] = {
  0,   /* field[0] = content */
};
static const ProtobufCIntRange exfiltration_response__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor exfiltration_response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "ExfiltrationResponse",
  "ExfiltrationResponse",
  "ExfiltrationResponse",
  "",
  sizeof(ExfiltrationResponse),
  1,
  exfiltration_response__field_descriptors,
  exfiltration_response__field_indices_by_name,
  1,  exfiltration_response__number_ranges,
  (ProtobufCMessageInit) exfiltration_response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define infiltration_response__field_descriptors NULL
#define infiltration_response__field_indices_by_name NULL
#define infiltration_response__number_ranges NULL
const ProtobufCMessageDescriptor infiltration_response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "InfiltrationResponse",
  "InfiltrationResponse",
  "InfiltrationResponse",
  "",
  sizeof(InfiltrationResponse),
  0,
  infiltration_response__field_descriptors,
  infiltration_response__field_indices_by_name,
  0,  infiltration_response__number_ranges,
  (ProtobufCMessageInit) infiltration_response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor read_dir_response__dir_entry__field_descriptors[3] =
{
  {
    "inode",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(ReadDirResponse__DirEntry, inode),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "file_type",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(ReadDirResponse__DirEntry, file_type),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pathname",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(ReadDirResponse__DirEntry, pathname),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned read_dir_response__dir_entry__field_indices_by_name[] = {
  1,   /* field[1] = file_type */
  0,   /* field[0] = inode */
  2,   /* field[2] = pathname */
};
static const ProtobufCIntRange read_dir_response__dir_entry__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor read_dir_response__dir_entry__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "ReadDirResponse.DirEntry",
  "DirEntry",
  "ReadDirResponse__DirEntry",
  "",
  sizeof(ReadDirResponse__DirEntry),
  3,
  read_dir_response__dir_entry__field_descriptors,
  read_dir_response__dir_entry__field_indices_by_name,
  1,  read_dir_response__dir_entry__number_ranges,
  (ProtobufCMessageInit) read_dir_response__dir_entry__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor read_dir_response__field_descriptors[1] =
{
  {
    "entries",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(ReadDirResponse, n_entries),
    offsetof(ReadDirResponse, entries),
    &read_dir_response__dir_entry__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned read_dir_response__field_indices_by_name[] = {
  0,   /* field[0] = entries */
};
static const ProtobufCIntRange read_dir_response__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor read_dir_response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "ReadDirResponse",
  "ReadDirResponse",
  "ReadDirResponse",
  "",
  sizeof(ReadDirResponse),
  1,
  read_dir_response__field_descriptors,
  read_dir_response__field_indices_by_name,
  1,  read_dir_response__number_ranges,
  (ProtobufCMessageInit) read_dir_response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define suicide_response__field_descriptors NULL
#define suicide_response__field_indices_by_name NULL
#define suicide_response__number_ranges NULL
const ProtobufCMessageDescriptor suicide_response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "suicideResponse",
  "SuicideResponse",
  "SuicideResponse",
  "",
  sizeof(SuicideResponse),
  0,
  suicide_response__field_descriptors,
  suicide_response__field_indices_by_name,
  0,  suicide_response__number_ranges,
  (ProtobufCMessageInit) suicide_response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue status__enum_values_by_number[7] =
{
  { "GOOD", "STATUS__GOOD", 0 },
  { "OPEN_ERROR", "STATUS__OPEN_ERROR", 1 },
  { "READ_ERROR", "STATUS__READ_ERROR", 2 },
  { "WRITE_ERROR", "STATUS__WRITE_ERROR", 3 },
  { "STAT_ERROR", "STATUS__STAT_ERROR", 4 },
  { "NOT_FILE", "STATUS__NOT_FILE", 5 },
  { "NOT_DIRECTORY", "STATUS__NOT_DIRECTORY", 6 },
};
static const ProtobufCIntRange status__value_ranges[] = {
{0, 0},{0, 7}
};
static const ProtobufCEnumValueIndex status__enum_values_by_name[7] =
{
  { "GOOD", 0 },
  { "NOT_DIRECTORY", 6 },
  { "NOT_FILE", 5 },
  { "OPEN_ERROR", 1 },
  { "READ_ERROR", 2 },
  { "STAT_ERROR", 4 },
  { "WRITE_ERROR", 3 },
};
const ProtobufCEnumDescriptor status__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "Status",
  "Status",
  "Status",
  "",
  7,
  status__enum_values_by_number,
  7,
  status__enum_values_by_name,
  1,
  status__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
