; void *memcpy(void *dst, void *src, size_t n)
memorycopy  PROC C
        push    edi
        mov     edi,[esp+8]
        mov     eax,edi
        push    esi
        mov     esi,[esp+16]
        mov     ecx,[esp+20]
        mov     edx,ecx
        shr     ecx,2
        and     edx,3
    rep movsd
        mov     ecx,edx
    rep movsb
        pop     esi
        pop     edi
        ret
memcpy  ENDP