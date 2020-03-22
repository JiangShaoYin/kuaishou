
echo "git Synchronizing begin !"
while((1))
do
    git add . && git commit -m "1" && git push origin master
    git pull origin master &> /dev/null
    sleep 30s
    echo "git Synchronizing......................................................................"
done
echo "git Synchronizing end !"




