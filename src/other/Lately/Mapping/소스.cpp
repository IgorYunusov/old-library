#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif


int main(){
    char rawData[] = {
		0xCC, 0xC3};

    #ifdef _WIN32

    HANDLE mem_handle = CreateFileMapping( INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0,  19, NULL);

    void* mem_map = MapViewOfFile( mem_handle, FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 0x0, 0x0, 19);

    #else // posix
    void* mem_map = mmap(NULL, sizeof(opcodes), PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    #endif

    memcpy(mem_map, rawData, sizeof(rawData));

    (( void(*)(int) )mem_map)(3);

    return 0;
}