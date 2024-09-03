# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """
from concurrent.futures import ThreadPoolExecutor
from threading import Lock
class Solution(object):
    def __init__(self):
        self.lock = Lock()
        self.queue = []
        self.visited = set()
        self.max_workers = 20
    def get_hostname(self, url):
        return  '.'.join(url.split('/')[2].split('.')[1:]) 
    
    def visit_url(self, current_url):
        next_urls = self.html_parser.getUrls(current_url)

        with self.lock:
            for url in next_urls:
                if url not in self.visited and self.current_hostname == self.get_hostname(url):
                    self.queue.append(url)
                    self.visited.add(url)
    def crawl(self, startUrl, htmlParser):
        """
        :type startUrl: str
        :type htmlParser: HtmlParser
        :rtype: List[str]
        """
        self.queue.append(startUrl)
        self.current_hostname = self.get_hostname(startUrl)
        self.visited.add(startUrl)
        self.html_parser = htmlParser

        executor = ThreadPoolExecutor(max_workers=self.max_workers)
        while self.queue:
            current_url = self.queue.pop()
            # create separate object to prevent deadlocks and infinite loops
            url_list = []
            url_list.append(current_url)
            # To ensure more urls to process in a batch
            while self.queue:
                current_url = self.queue.pop()
                url_list.append(current_url)

            executor_list = []
            # Execute this batch of threads with threadpool
            for q in url_list:
                executor_list.append(executor.submit(self.visit_url, q))
            
            for future in executor_list:
                future.result()
        executor.shutdown()

        return list(self.visited)