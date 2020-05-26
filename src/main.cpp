#include "symbol_table.hpp"
#include "StrTable.hpp"
#include "RegisterPool.hpp"
#include "OffSets.hpp"

extern int yyparse();

int main()
{
  std::clog.setstate(std::ios_base::failbit);
  reg_pool.preload();
  globl_offsets.preload();
  symbol_table.enter_scope();
  yyparse();
};
