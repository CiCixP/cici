#include "AECL2006CHFTableTest.h"

TEST_F(AECL2006CHFTableTest, test)
{
  // testing four points
  EXPECT_NEAR(_chf_table->chf(14000, 3500, 0.2), 1140, 1e-15);
  EXPECT_NEAR(_chf_table->chf(5000, 1350, 0.5), 2495.2, 1e-15);
  EXPECT_NEAR(_chf_table->chf(8200, 6500, 0.15), 2344.2, 1e-15);
  EXPECT_NEAR(_chf_table->chf(300, 100, 0.02), 2442.8, 1e-15);

  // testing max mass flux
  EXPECT_NEAR(_chf_table->getMaxMassFlux(), 8000, 1e-15);
}
