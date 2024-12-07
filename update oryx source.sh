# First get the ORYX compile hash (downloading the compiled bin file will have the hash in the file name),
# then run these commands
curl -L "https://oryx.zsa.io/source/nQPvR" -o source.zip
# unzip source.zip
# then copy the source files to the keyboards/zsa/voyager/keymaps/jrstrunk directory
qmk compile
