#include <stan/io/cmd_line.hpp>
#include <gtest/gtest.h>

TEST(io_cmd_line, cmd_line_0) {
  int argc = 0;
  const char* argv[1];
  argv[0] = "foo";
  stan::io::cmd_line cl(argc,argv);
  EXPECT_FALSE(cl.has_key("bar"));
  std::string y;
  EXPECT_FALSE(cl.val<std::string>("bar",y));
}

TEST(io_cmd_line, cmd_line_string) {
  int argc = 2;
  const char* argv[2];
  argv[0] = "prog";
  argv[1] = "--foo=bar";
  stan::io::cmd_line cl(argc,argv);
  std::string x;
  EXPECT_TRUE(cl.val<std::string>("foo",x));
  EXPECT_EQ("bar",x);
}

TEST(io_cmd_line, cmd_line_int) {
  int argc = 6;
  const char* argv[6];
  argv[0] = "prog.exe";
  argv[1] = "--foo=bar";
  argv[2] = "--bz";
  argv[3] = "--bing=3";
  argv[4] = "ahoy";
  argv[5] = "17";
  stan::io::cmd_line cl(argc,argv);
  EXPECT_EQ("prog.exe",cl.command());
  std::string x;
  EXPECT_TRUE(cl.val<std::string>("foo",x));
  EXPECT_EQ("bar",x);
  unsigned int y;
  EXPECT_TRUE(cl.val<unsigned int>("bing",y));
  EXPECT_EQ(3U,y);
  EXPECT_TRUE(cl.has_flag("bz"));
  EXPECT_FALSE(cl.has_flag("bza"));
  EXPECT_FALSE(cl.val<unsigned int>("bongo",y));
  EXPECT_EQ(2U, cl.bare_size());
  std::string z;
  EXPECT_TRUE(cl.bare<std::string>(0,z));
  EXPECT_EQ("ahoy", z);
  EXPECT_TRUE(cl.bare<unsigned int>(1,y));
  EXPECT_EQ(17U, y);
  double aaa;
  EXPECT_FALSE(cl.bare<double>(2,aaa));
}
