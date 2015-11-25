#include<libnet.h>

int mock_libnet_null_ok = 1;
int mock_libnet_lo_ok = 1;

void
libnet_destroy(libnet_t* l)
{
        free(l);
}

libnet_t*
libnet_init(int injection_type, const char *device, char *err_buf)
{
        if (device == NULL) {
                if (mock_libnet_null_ok) {
                        return malloc(1);
                }
                return NULL;
        }
        if (!strcmp(device, "bad")) {
                return NULL;
        }
        if (!strcmp(device, "good")) {
                return malloc(1);
        }
        if (mock_libnet_lo_ok && !strcmp(device, "lo")) {
                return malloc(1);
        }
        return NULL;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vim: ts=8 sw=8
 */