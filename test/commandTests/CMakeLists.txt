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

