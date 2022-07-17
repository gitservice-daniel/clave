global common_syscall_handler
extern syscall_handler

common_syscall_handler:
    push edx
    push esi
    push edi
    push eax
    call syscall_handler
    pop eax
    pop edi
    pop esi
    pop edx
    iret