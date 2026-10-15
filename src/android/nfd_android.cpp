// Stand-in for nativefiledialog-extended on Android, which has no native file dialogs.
// Every dialog reports "cancelled". The ROM is picked in Java before the game starts
// (android/app/src/main/java/io/github/locme/banjotooie/LauncherActivity.java).

#include "nfd.h"

extern "C" {

nfdresult_t NFD_Init(void) { return NFD_OKAY; }
void NFD_Quit(void) {}

const char* NFD_GetError(void) { return "File dialogs are not available on Android"; }
void NFD_ClearError(void) {}

void NFD_FreePathN(nfdnchar_t*) {}
void NFD_FreePathU8(nfdu8char_t*) {}

nfdresult_t NFD_OpenDialogN(nfdnchar_t** outPath, const nfdnfilteritem_t*, nfdfiltersize_t, const nfdnchar_t*) {
    *outPath = nullptr;
    return NFD_CANCEL;
}
nfdresult_t NFD_OpenDialogU8(nfdu8char_t** outPath, const nfdu8filteritem_t*, nfdfiltersize_t, const nfdu8char_t*) {
    *outPath = nullptr;
    return NFD_CANCEL;
}

nfdresult_t NFD_OpenDialogMultipleN(const nfdpathset_t** outPaths, const nfdnfilteritem_t*, nfdfiltersize_t, const nfdnchar_t*) {
    *outPaths = nullptr;
    return NFD_CANCEL;
}
nfdresult_t NFD_OpenDialogMultipleU8(const nfdpathset_t** outPaths, const nfdu8filteritem_t*, nfdfiltersize_t, const nfdu8char_t*) {
    *outPaths = nullptr;
    return NFD_CANCEL;
}

nfdresult_t NFD_SaveDialogN(nfdnchar_t** outPath, const nfdnfilteritem_t*, nfdfiltersize_t, const nfdnchar_t*, const nfdnchar_t*) {
    *outPath = nullptr;
    return NFD_CANCEL;
}
nfdresult_t NFD_SaveDialogU8(nfdu8char_t** outPath, const nfdu8filteritem_t*, nfdfiltersize_t, const nfdu8char_t*, const nfdu8char_t*) {
    *outPath = nullptr;
    return NFD_CANCEL;
}

nfdresult_t NFD_PickFolderN(nfdnchar_t** outPath, const nfdnchar_t*) {
    *outPath = nullptr;
    return NFD_CANCEL;
}
nfdresult_t NFD_PickFolderU8(nfdu8char_t** outPath, const nfdu8char_t*) {
    *outPath = nullptr;
    return NFD_CANCEL;
}

// No dialog ever returns a path set, so these are never handed a real one.
nfdresult_t NFD_PathSet_GetCount(const nfdpathset_t*, nfdpathsetsize_t* count) {
    *count = 0;
    return NFD_OKAY;
}
nfdresult_t NFD_PathSet_GetPathN(const nfdpathset_t*, nfdpathsetsize_t, nfdnchar_t** outPath) {
    *outPath = nullptr;
    return NFD_ERROR;
}
nfdresult_t NFD_PathSet_GetPathU8(const nfdpathset_t*, nfdpathsetsize_t, nfdu8char_t** outPath) {
    *outPath = nullptr;
    return NFD_ERROR;
}
void NFD_PathSet_FreePathN(const nfdnchar_t*) {}
void NFD_PathSet_FreePathU8(const nfdu8char_t*) {}
nfdresult_t NFD_PathSet_GetEnum(const nfdpathset_t*, nfdpathsetenum_t* outEnumerator) {
    outEnumerator->ptr = nullptr;
    return NFD_OKAY;
}
void NFD_PathSet_FreeEnum(nfdpathsetenum_t*) {}
nfdresult_t NFD_PathSet_EnumNextN(nfdpathsetenum_t*, nfdnchar_t** outPath) {
    *outPath = nullptr;
    return NFD_OKAY;
}
nfdresult_t NFD_PathSet_EnumNextU8(nfdpathsetenum_t*, nfdu8char_t** outPath) {
    *outPath = nullptr;
    return NFD_OKAY;
}
void NFD_PathSet_Free(const nfdpathset_t*) {}

}
