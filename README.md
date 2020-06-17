# FormatMessage

This application demonstrate the Window's FormatMessage function.
A lightweight C++ wrapper CFormatMessage is provided as a helper.

The application, itself, displays a number of messages with the following output:

```
Test: ERROR_SUCCESS (Default)
MessageId: 0
MessageText: The operation completed successfully.

Test: ERROR_SUCCESS (French Française)
MessageId: 0
MessageText: L’opération a réussi.

Test: ERROR_SUCCESS (Japanese 日本語)
MessageId: 0
MessageText: この操作を正しく終了しました。

Test: ERROR_INVALID_FUNCTION
MessageId: 1
MessageText: Incorrect function.

Test: ERROR_FILE_NOT_FOUND
MessageId: 2
MessageText: The system cannot find the file specified.

You may need to set an appropriate Console font to see asian (Japanese) characters correctly (e.g. NSimSun).

Test: ERROR_ACCESS_DENIED
MessageId: 5
MessageText: Access is denied.

Test: ERROR_INVALID_HANDLE
MessageId: 6
MessageText: The handle is invalid.

Test: ERROR_NOT_ENOUGH_MEMORY
MessageId: 8
MessageText: Not enough memory resources are available to process this command.

Test: ERROR_OUTOFMEMORY
MessageId: 14
MessageText: Not enough memory resources are available to complete this operation.

Test: ERROR_NOT_SUPPORTED
MessageId: 50
MessageText: The request is not supported.
```
