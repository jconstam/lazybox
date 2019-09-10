# This file was automatically generated.  Do not modify.

add_test( lazybox ${OUTPUT_PATH}/lazybox )
set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION "LazyBox - BusyBox's less portable, less functional cousin." )

add_test( NAME basename_noFile WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" )
add_test( NAME basename_noFile_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" )
add_test( NAME basename_noFile_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/basename  )

add_test( NAME basename_singleFile WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/file.ext )
add_test( NAME basename_singleFile_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/file.ext )
add_test( NAME basename_singleFile_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/basename /path/to/the/file.ext )

add_test( NAME basename_singleFileWithExt WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/file.ext .ext )
add_test( NAME basename_singleFileWithExt_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/file.ext .ext )
add_test( NAME basename_singleFileWithExt_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/basename /path/to/the/file.ext .ext )

add_test( NAME basename_singleFileWithExtWrong WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/file.ext .ext2 )
add_test( NAME basename_singleFileWithExtWrong_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/file.ext .ext2 )
add_test( NAME basename_singleFileWithExtWrong_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/basename /path/to/the/file.ext .ext2 )

add_test( NAME basename_singleFolder WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/folder/ )
add_test( NAME basename_singleFolder_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/folder/ )
add_test( NAME basename_singleFolder_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/basename /path/to/the/folder/ )

add_test( NAME basename_singleFolderWithExt WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/folder/ .ext )
add_test( NAME basename_singleFolderWithExt_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command basename --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /path/to/the/folder/ .ext )
add_test( NAME basename_singleFolderWithExt_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/basename /path/to/the/folder/ .ext )

add_test( NAME cat_multiFile1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_multiFile1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_multiFile1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 )

add_test( NAME cat_multiFileLineNums1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_multiFileLineNums1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_multiFileLineNums1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 )

add_test( NAME cat_multiFileLineNums2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_multiFileLineNums2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_multiFileLineNums2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3 )

add_test( NAME cat_multiFileLineNums3 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -b ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_multiFileLineNums3_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -b ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_multiFileLineNums3_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -b ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3 )

add_test( NAME cat_singleFile1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFile1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFile1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat ${COMMAND_TEST_ROOT}/cat/test1 )

add_test( NAME cat_singleFile2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_singleFile2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_singleFile2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat ${COMMAND_TEST_ROOT}/cat/test2 )

add_test( NAME cat_singleFileLineNums WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileLineNums_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileLineNums_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -n ${COMMAND_TEST_ROOT}/cat/test1 )

add_test( NAME cat_singleFileLineNumsNonBlank1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_singleFileLineNumsNonBlank1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_singleFileLineNumsNonBlank1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -n ${COMMAND_TEST_ROOT}/cat/test3 )

add_test( NAME cat_singleFileLineNumsNonBlank2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -b ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_singleFileLineNumsNonBlank2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -b ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_singleFileLineNumsNonBlank2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -b ${COMMAND_TEST_ROOT}/cat/test3 )

add_test( NAME cat_singleFileShowAll1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -A ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowAll1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -A ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowAll1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -A ${COMMAND_TEST_ROOT}/cat/test4 )

add_test( NAME cat_singleFileShowAll2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -A ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowAll2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -A ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowAll2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -A ${COMMAND_TEST_ROOT}/cat/test5 )

add_test( NAME cat_singleFileShowAllNoEnds1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -t ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowAllNoEnds1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -t ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowAllNoEnds1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -t ${COMMAND_TEST_ROOT}/cat/test4 )

add_test( NAME cat_singleFileShowAllNoEnds2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -t ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowAllNoEnds2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -t ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowAllNoEnds2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -t ${COMMAND_TEST_ROOT}/cat/test5 )

add_test( NAME cat_singleFileShowAllNoTabs1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowAllNoTabs1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowAllNoTabs1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -e ${COMMAND_TEST_ROOT}/cat/test4 )

add_test( NAME cat_singleFileShowAllNoTabs2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowAllNoTabs2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowAllNoTabs2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -e ${COMMAND_TEST_ROOT}/cat/test5 )

add_test( NAME cat_singleFileShowEnds1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -E ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileShowEnds1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -E ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileShowEnds1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -E ${COMMAND_TEST_ROOT}/cat/test1 )

add_test( NAME cat_singleFileShowEnds2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -E ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_singleFileShowEnds2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -E ${COMMAND_TEST_ROOT}/cat/test2 )
add_test( NAME cat_singleFileShowEnds2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -E ${COMMAND_TEST_ROOT}/cat/test2 )

add_test( NAME cat_singleFileShowNonPrintable1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -v ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowNonPrintable1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -v ${COMMAND_TEST_ROOT}/cat/test5 )
add_test( NAME cat_singleFileShowNonPrintable1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -v ${COMMAND_TEST_ROOT}/cat/test5 )

add_test( NAME cat_singleFileShowTabs1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -T ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileShowTabs1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -T ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileShowTabs1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -T ${COMMAND_TEST_ROOT}/cat/test1 )

add_test( NAME cat_singleFileShowTabs2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowTabs2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowTabs2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat ${COMMAND_TEST_ROOT}/cat/test4 )

add_test( NAME cat_singleFileShowTabs3 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -T ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowTabs3_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -T ${COMMAND_TEST_ROOT}/cat/test4 )
add_test( NAME cat_singleFileShowTabs3_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -T ${COMMAND_TEST_ROOT}/cat/test4 )

add_test( NAME cat_singleFileSqueeze1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -s ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileSqueeze1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -s ${COMMAND_TEST_ROOT}/cat/test1 )
add_test( NAME cat_singleFileSqueeze1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -s ${COMMAND_TEST_ROOT}/cat/test1 )

add_test( NAME cat_singleFileSqueeze2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -s ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_singleFileSqueeze2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cat --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -s ${COMMAND_TEST_ROOT}/cat/test3 )
add_test( NAME cat_singleFileSqueeze2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cat -s ${COMMAND_TEST_ROOT}/cat/test3 )

add_test( NAME cksum_directory WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT} )
add_test( NAME cksum_directory_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT} )
add_test( NAME cksum_directory_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum ${COMMAND_TEST_ROOT} )

add_test( NAME cksum_directoryWithFile WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT} ${COMMAND_TEST_ROOT}/cksum/test1 )
add_test( NAME cksum_directoryWithFile_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT} ${COMMAND_TEST_ROOT}/cksum/test1 )
add_test( NAME cksum_directoryWithFile_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum ${COMMAND_TEST_ROOT} ${COMMAND_TEST_ROOT}/cksum/test1 )

add_test( NAME cksum_multipleFile1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/test1 ${COMMAND_TEST_ROOT}/cksum/test2 )
add_test( NAME cksum_multipleFile1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/test1 ${COMMAND_TEST_ROOT}/cksum/test2 )
add_test( NAME cksum_multipleFile1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum ${COMMAND_TEST_ROOT}/cksum/test1 ${COMMAND_TEST_ROOT}/cksum/test2 )

add_test( NAME cksum_singleFile WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/test1 )
add_test( NAME cksum_singleFile_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/test1 )
add_test( NAME cksum_singleFile_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum ${COMMAND_TEST_ROOT}/cksum/test1 )

add_test( NAME cksum_singleFileDoesNotExist1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/notAFile )
add_test( NAME cksum_singleFileDoesNotExist1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/notAFile )
add_test( NAME cksum_singleFileDoesNotExist1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum ${COMMAND_TEST_ROOT}/cksum/notAFile )

add_test( NAME cksum_singleFileDoesNotExist2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/notAFile ${COMMAND_TEST_ROOT}/cksum/test1 )
add_test( NAME cksum_singleFileDoesNotExist2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters ${COMMAND_TEST_ROOT}/cksum/notAFile ${COMMAND_TEST_ROOT}/cksum/test1 )
add_test( NAME cksum_singleFileDoesNotExist2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum ${COMMAND_TEST_ROOT}/cksum/notAFile ${COMMAND_TEST_ROOT}/cksum/test1 )

add_test( NAME cksum_singleFileLarge WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /bin/bash )
add_test( NAME cksum_singleFileLarge_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command cksum --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters /bin/bash )
add_test( NAME cksum_singleFileLarge_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/cksum /bin/bash )

add_test( NAME date_dateFormat01 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%%" )
add_test( NAME date_dateFormat01_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%%" )
add_test( NAME date_dateFormat01_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%%" )

add_test( NAME date_dateFormat02 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%a   %-a   %_a   %0a   %^a   %#a" )
add_test( NAME date_dateFormat02_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%a   %-a   %_a   %0a   %^a   %#a" )
add_test( NAME date_dateFormat02_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%a   %-a   %_a   %0a   %^a   %#a" )

add_test( NAME date_dateFormat03 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%A   %-A   %_A   %0A   %^A   %#A" )
add_test( NAME date_dateFormat03_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%A   %-A   %_A   %0A   %^A   %#A" )
add_test( NAME date_dateFormat03_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%A   %-A   %_A   %0A   %^A   %#A" )

add_test( NAME date_dateFormat04 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%b   %-b   %_b   %0b   %^b   %#b" )
add_test( NAME date_dateFormat04_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%b   %-b   %_b   %0b   %^b   %#b" )
add_test( NAME date_dateFormat04_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%b   %-b   %_b   %0b   %^b   %#b" )

add_test( NAME date_dateFormat05 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%B   %-B   %_B   %0B   %^B   %#B" )
add_test( NAME date_dateFormat05_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%B   %-B   %_B   %0B   %^B   %#B" )
add_test( NAME date_dateFormat05_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%B   %-B   %_B   %0B   %^B   %#B" )

add_test( NAME date_dateFormat07 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%C   %-C   %_C   %0C   %^C   %#C" )
add_test( NAME date_dateFormat07_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%C   %-C   %_C   %0C   %^C   %#C" )
add_test( NAME date_dateFormat07_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%C   %-C   %_C   %0C   %^C   %#C" )

add_test( NAME date_dateFormat08 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%d   %-d   %_d   %0d   %^d   %#d" )
add_test( NAME date_dateFormat08_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%d   %-d   %_d   %0d   %^d   %#d" )
add_test( NAME date_dateFormat08_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%d   %-d   %_d   %0d   %^d   %#d" )

add_test( NAME date_dateFormat09 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%D   %-D   %_D   %0D   %^D   %#D" )
add_test( NAME date_dateFormat09_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%D   %-D   %_D   %0D   %^D   %#D" )
add_test( NAME date_dateFormat09_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%D   %-D   %_D   %0D   %^D   %#D" )

add_test( NAME date_dateFormat10 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%e   %-e   %_e   %0e   %^e   %#e" )
add_test( NAME date_dateFormat10_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%e   %-e   %_e   %0e   %^e   %#e" )
add_test( NAME date_dateFormat10_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%e   %-e   %_e   %0e   %^e   %#e" )

add_test( NAME date_dateFormat11 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%F   %-F   %_F   %0F   %^F   %#F" )
add_test( NAME date_dateFormat11_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%F   %-F   %_F   %0F   %^F   %#F" )
add_test( NAME date_dateFormat11_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%F   %-F   %_F   %0F   %^F   %#F" )

add_test( NAME date_dateFormat12 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%g   %-g   %_g   %0g   %^g   %#g" )
add_test( NAME date_dateFormat12_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%g   %-g   %_g   %0g   %^g   %#g" )
add_test( NAME date_dateFormat12_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%g   %-g   %_g   %0g   %^g   %#g" )

add_test( NAME date_dateFormat13 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%G   %-G   %_G   %0G   %^G   %#G" )
add_test( NAME date_dateFormat13_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%G   %-G   %_G   %0G   %^G   %#G" )
add_test( NAME date_dateFormat13_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%G   %-G   %_G   %0G   %^G   %#G" )

add_test( NAME date_dateFormat14 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%h   %-h   %_h   %0h   %^h   %#h" )
add_test( NAME date_dateFormat14_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%h   %-h   %_h   %0h   %^h   %#h" )
add_test( NAME date_dateFormat14_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%h   %-h   %_h   %0h   %^h   %#h" )

add_test( NAME date_dateFormat15 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%H   %-H   %_H   %0H   %^H   %#H" )
add_test( NAME date_dateFormat15_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%H   %-H   %_H   %0H   %^H   %#H" )
add_test( NAME date_dateFormat15_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%H   %-H   %_H   %0H   %^H   %#H" )

add_test( NAME date_dateFormat16 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%I   %-I   %_I   %0I   %^I   %#I" )
add_test( NAME date_dateFormat16_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%I   %-I   %_I   %0I   %^I   %#I" )
add_test( NAME date_dateFormat16_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%I   %-I   %_I   %0I   %^I   %#I" )

add_test( NAME date_dateFormat17 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%j   %-j   %_j   %0j   %^j   %#j" )
add_test( NAME date_dateFormat17_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%j   %-j   %_j   %0j   %^j   %#j" )
add_test( NAME date_dateFormat17_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%j   %-j   %_j   %0j   %^j   %#j" )

add_test( NAME date_dateFormat18 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%k   %-k   %_k   %0k   %^k   %#k" )
add_test( NAME date_dateFormat18_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%k   %-k   %_k   %0k   %^k   %#k" )
add_test( NAME date_dateFormat18_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%k   %-k   %_k   %0k   %^k   %#k" )

add_test( NAME date_dateFormat19 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%l   %-l   %_l   %0l   %^l   %#l" )
add_test( NAME date_dateFormat19_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%l   %-l   %_l   %0l   %^l   %#l" )
add_test( NAME date_dateFormat19_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%l   %-l   %_l   %0l   %^l   %#l" )

add_test( NAME date_dateFormat20 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%m   %-m   %_m   %0m   %^m   %#m" )
add_test( NAME date_dateFormat20_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%m   %-m   %_m   %0m   %^m   %#m" )
add_test( NAME date_dateFormat20_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%m   %-m   %_m   %0m   %^m   %#m" )

add_test( NAME date_dateFormat21 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%M   %-M   %_M   %0M   %^M   %#M" )
add_test( NAME date_dateFormat21_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%M   %-M   %_M   %0M   %^M   %#M" )
add_test( NAME date_dateFormat21_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%M   %-M   %_M   %0M   %^M   %#M" )

add_test( NAME date_dateFormat22 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%n   %-n   %_n   %0n   %^n   %#n" )
add_test( NAME date_dateFormat22_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%n   %-n   %_n   %0n   %^n   %#n" )
add_test( NAME date_dateFormat22_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%n   %-n   %_n   %0n   %^n   %#n" )

add_test( NAME date_dateFormat24 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%p   %-p   %_p   %0p   %^p   %#p" )
add_test( NAME date_dateFormat24_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%p   %-p   %_p   %0p   %^p   %#p" )
add_test( NAME date_dateFormat24_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%p   %-p   %_p   %0p   %^p   %#p" )

add_test( NAME date_dateFormat25 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%P   %-P   %_P   %0P   %^P   %#P" )
add_test( NAME date_dateFormat25_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%P   %-P   %_P   %0P   %^P   %#P" )
add_test( NAME date_dateFormat25_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%P   %-P   %_P   %0P   %^P   %#P" )

add_test( NAME date_dateFormat27 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%r   %-r   %_r   %0r   %^r   %#r" )
add_test( NAME date_dateFormat27_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%r   %-r   %_r   %0r   %^r   %#r" )
add_test( NAME date_dateFormat27_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%r   %-r   %_r   %0r   %^r   %#r" )

add_test( NAME date_dateFormat28 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%R   %-R   %_R   %0R   %^R   %#R" )
add_test( NAME date_dateFormat28_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%R   %-R   %_R   %0R   %^R   %#R" )
add_test( NAME date_dateFormat28_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%R   %-R   %_R   %0R   %^R   %#R" )

add_test( NAME date_dateFormat30 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%S   %-S   %_S   %0S   %^S   %#S" )
add_test( NAME date_dateFormat30_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%S   %-S   %_S   %0S   %^S   %#S" )
add_test( NAME date_dateFormat30_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%S   %-S   %_S   %0S   %^S   %#S" )

add_test( NAME date_dateFormat31 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%t   %-t   %_t   %0t   %^t   %#t" )
add_test( NAME date_dateFormat31_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%t   %-t   %_t   %0t   %^t   %#t" )
add_test( NAME date_dateFormat31_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%t   %-t   %_t   %0t   %^t   %#t" )

add_test( NAME date_dateFormat32 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%T   %-T   %_T   %0T   %^T   %#T" )
add_test( NAME date_dateFormat32_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%T   %-T   %_T   %0T   %^T   %#T" )
add_test( NAME date_dateFormat32_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%T   %-T   %_T   %0T   %^T   %#T" )

add_test( NAME date_dateFormat33 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%u   %-u   %_u   %0u   %^u   %#u" )
add_test( NAME date_dateFormat33_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%u   %-u   %_u   %0u   %^u   %#u" )
add_test( NAME date_dateFormat33_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%u   %-u   %_u   %0u   %^u   %#u" )

add_test( NAME date_dateFormat34 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%U   %-U   %_U   %0U   %^U   %#U" )
add_test( NAME date_dateFormat34_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%U   %-U   %_U   %0U   %^U   %#U" )
add_test( NAME date_dateFormat34_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%U   %-U   %_U   %0U   %^U   %#U" )

add_test( NAME date_dateFormat35 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%V   %-V   %_V   %0V   %^V   %#V" )
add_test( NAME date_dateFormat35_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%V   %-V   %_V   %0V   %^V   %#V" )
add_test( NAME date_dateFormat35_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%V   %-V   %_V   %0V   %^V   %#V" )

add_test( NAME date_dateFormat36 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%w   %-w   %_w   %0w   %^w   %#w" )
add_test( NAME date_dateFormat36_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%w   %-w   %_w   %0w   %^w   %#w" )
add_test( NAME date_dateFormat36_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%w   %-w   %_w   %0w   %^w   %#w" )

add_test( NAME date_dateFormat37 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%W   %-W   %_W   %0W   %^W   %#W" )
add_test( NAME date_dateFormat37_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%W   %-W   %_W   %0W   %^W   %#W" )
add_test( NAME date_dateFormat37_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%W   %-W   %_W   %0W   %^W   %#W" )

add_test( NAME date_dateFormat38 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%x   %-x   %_x   %0x   %^x   %#x" )
add_test( NAME date_dateFormat38_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%x   %-x   %_x   %0x   %^x   %#x" )
add_test( NAME date_dateFormat38_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%x   %-x   %_x   %0x   %^x   %#x" )

add_test( NAME date_dateFormat39 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%X   %-X   %_X   %0X   %^X   %#X" )
add_test( NAME date_dateFormat39_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%X   %-X   %_X   %0X   %^X   %#X" )
add_test( NAME date_dateFormat39_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%X   %-X   %_X   %0X   %^X   %#X" )

add_test( NAME date_dateFormat40 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%y   %-y   %_y   %0y   %^y   %#y" )
add_test( NAME date_dateFormat40_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%y   %-y   %_y   %0y   %^y   %#y" )
add_test( NAME date_dateFormat40_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%y   %-y   %_y   %0y   %^y   %#y" )

add_test( NAME date_dateFormat41 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%Y   %-Y   %_Y   %0Y   %^Y   %#Y" )
add_test( NAME date_dateFormat41_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "+%Y   %-Y   %_Y   %0Y   %^Y   %#Y" )
add_test( NAME date_dateFormat41_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date "+%Y   %-Y   %_Y   %0Y   %^Y   %#Y" )

add_test( NAME date_noparams WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" )
add_test( NAME date_noparams_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command date --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" )
add_test( NAME date_noparams_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/date  )

add_test( NAME echo_escape_newline1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\n )
add_test( NAME echo_escape_newline1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\n )
add_test( NAME echo_escape_newline1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -e testing\n )

add_test( NAME echo_escape_newline2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e -n testing\n )
add_test( NAME echo_escape_newline2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e -n testing\n )
add_test( NAME echo_escape_newline2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -e -n testing\n )

add_test( NAME echo_escape_newline3 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\n\n\ntesting\ntesting )
add_test( NAME echo_escape_newline3_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\n\n\ntesting\ntesting )
add_test( NAME echo_escape_newline3_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -e testing\n\n\ntesting\ntesting )

add_test( NAME echo_escape_newline4 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters testing\\n )
add_test( NAME echo_escape_newline4_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters testing\\n )
add_test( NAME echo_escape_newline4_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo testing\\n )

add_test( NAME echo_escape_tab1 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\ttesting )
add_test( NAME echo_escape_tab1_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\ttesting )
add_test( NAME echo_escape_tab1_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -e testing\ttesting )

add_test( NAME echo_escape_tab2 WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\t\t\ttesting )
add_test( NAME echo_escape_tab2_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -e testing\t\t\ttesting )
add_test( NAME echo_escape_tab2_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -e testing\t\t\ttesting )

add_test( NAME echo_many WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "this is a lot of parameters and some are numbers 1 2 3" )
add_test( NAME echo_many_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "this is a lot of parameters and some are numbers 1 2 3" )
add_test( NAME echo_many_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo "this is a lot of parameters and some are numbers 1 2 3" )

add_test( NAME echo_nonewline_many WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n this is a lot of parameters and some are numbers 1 2 3 )
add_test( NAME echo_nonewline_many_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n this is a lot of parameters and some are numbers 1 2 3 )
add_test( NAME echo_nonewline_many_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -n this is a lot of parameters and some are numbers 1 2 3 )

add_test( NAME echo_nonewline_one WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n testing )
add_test( NAME echo_nonewline_one_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters -n testing )
add_test( NAME echo_nonewline_one_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo -n testing )

add_test( NAME echo_nothing WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" )
add_test( NAME echo_nothing_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" )
add_test( NAME echo_nothing_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo  )

add_test( NAME echo_one WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "testing" )
add_test( NAME echo_one_symlink WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runTest.py --useSymlink --command echo --buildPath "${OUTPUT_PATH}" --workingPath "${BUILD_PATH}" --parameters "testing" )
add_test( NAME echo_one_valgrind WORKING_DIRECTORY /mnt/c/Users/callm/Documents/dev/lazybox/test/commandTests COMMAND ${SCRIPT_PATH}/runValgrind.sh ${OUTPUT_PATH}/echo "testing" )

