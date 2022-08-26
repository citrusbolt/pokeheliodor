/* This small function uses all the arithmetic operators that
   libgcc1.c can handle.  If you can link it, then
   you have provided replacements for all the libgcc1.c functions that
   your target machine needs.  */

int foo ();
double dfoo ();

/* We don't want __main here because that can drag in atexit (among other
   things) which won't necessarily exist yet.  */

main_without__main ()
{
  int a = foo (), b = foo ();
  unsigned int au = foo (), bu = foo ();
  float af = dfoo (), bf = dfoo ();
  double ad = dfoo (), bd = dfoo ();

  discard (a * b);
  discard (a / b);
  discard (a % b);

  discard (au / bu);
  discard (au % bu);

  discard (a >> b);
  discard (a << b);

  discard (au >> bu);
  discard (au << bu);

  ddiscard (ad + bd);
  ddiscard (ad - bd);
  ddiscard (ad * bd);
  ddiscard (ad / bd);
  ddiscard (-ad);

  ddiscard (af + bf);
  ddiscard (af - bf);
  ddiscard (af * bf);
  ddiscard (af / bf);
  ddiscard (-af);

  discard ((int) ad);
  discard ((int) af);

  ddiscard ((double) a);
  ddiscard ((float) a);
  ddiscard ((float) ad);

  discard (ad == bd);
  discard (ad < bd);
  discard (ad > bd);
  discard (ad != bd);
  discard (ad <= bd);
  discard (ad >= bd);

  discard (af == bf);
  discard (af < bf);
  discard (af > bf);
  discard (af != bf);
  discard (af <= bf);
  discard (af >= bf);

  return 0;
}

discard (x)
     int x;
{}

ddiscard (x)
     double x;
{}

foo ()
{
  static int table[] = {20, 69, 4, 12};
  static int idx;

  return table[idx++];
}

double
dfoo ()
{
  static double table[] = {20.4, 69.96, 4.4, 202.202};
  static int idx;

  return table[idx++];
}

/* Provide functions that some versions of the linker use to default
   the start address if -e symbol is not used, to avoid the warning
   message saying the start address is defaulted.  */
extern void start() __asm__("start");
extern void _start() __asm__("_start");
extern void __start() __asm__("__start");

/* Provide functions that might be needed by soft-float emulation routines.  */
void memcpy() {}

void start() {}
void _start() {}
void __start() {}
void mainCRTStartup() {}

/* CYGNUS LOCAL - duplicate definition of memcpy() removed.  */

/* CYGNUS LOCAL v850 */
#if defined __v850e__ || defined __v850ea__
/* We need to use the symbol __ctbp in order to force the linker to define it.  */
extern int _ctbp;

void _func() { _ctbp = 1; }
#endif
/* END CYGNUS LOCAL */
